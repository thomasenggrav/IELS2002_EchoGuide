/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-hc-sr04-ultrasonic-arduino/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
*********/

const int trigPin = 5;
const int echoPin = 18;
const int motorPin = 13;  

// Definerer Lydens hastighet in cm
#define SOUND_SPEED 0.034

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200);             // Starter Seriell Komunikasjon
  pinMode(trigPin, OUTPUT);          // Setter trigPin til Høy
  pinMode(echoPin, INPUT);           // Setter echoPin som input
  pinMode(motorPin, OUTPUT);         // Setter motorPin som Output
}

void loop() {
  // Clearer trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Setter trigPin til HIGH i 10 mikrosekunder
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Leser echoPin, returner lydbølge reiseti i mikrosekunder
  duration = pulseIn(echoPin, HIGH);
  
  // kalkuler avstand
  distanceCm = duration * SOUND_SPEED / 2;
  
  // Skriver avstand til Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  
  // Sjekk om av stand er mindre enn 10 cm
  if (distanceCm < 10) {
    // Skru på motor hvis avstand er mindre enn 10 cm
    digitalWrite(motorPin, HIGH);
  } else {
    // Skru av motor hvis avstand er mer enn 10 cm
    digitalWrite(motorPin, LOW);
  }
  
  delay(1000);  // Delay
}
