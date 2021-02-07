#include <Servo.h>

const int buttonPin = 5;
const int servoPin = 6;
const int servoCtrlPin = 7;
const int ledPin = 13;

const int CLOSED_POSITION = 170;
const int OPENED_POSITION = 50;

Servo myservo;

int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(servoCtrlPin, OUTPUT);
  
  digitalWrite(buttonPin, HIGH);
  
  digitalWrite(servoCtrlPin, HIGH);
  myservo.attach(servoPin);
  myservo.write(CLOSED_POSITION);
  delay (250);
  myservo.detach();
  digitalWrite(servoCtrlPin, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  digitalWrite(ledPin, !buttonState);
  
  if(buttonState == LOW) {
    // Button is pressed!
    // open the Slot for 250 ms and close it afterwards
    myservo.attach(servoPin);
    digitalWrite(servoCtrlPin, HIGH);
    
    myservo.write(OPENED_POSITION);
    delay(250);
    myservo.write(CLOSED_POSITION); 
    delay (250);
    
    digitalWrite(servoCtrlPin, LOW);
    
    myservo.detach();
    delay(1000*5); // For the next 5 seconds it's not possible to get further food. Change this to fit your needs.
  }
}
