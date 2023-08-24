#define CW 5   
#define CCW 6  
#define RIGHT_SENSOR_PIN 11   // Right photomicrosensor pin
#define LEFT_SENSOR_PIN 10   // Left photomicrosensor pin

void rotateCW(int angleDegrees) {
  int steps = angleDegrees / 0.72;
  
  for (int i = 0; i < steps; i++) {
    digitalWrite(CW, HIGH);
    delayMicroseconds(3600); 
    digitalWrite(CW, LOW);
    delayMicroseconds(3600);
  }
}

void rotateCCW(int angleDegrees) {
  int steps = angleDegrees / 0.72;
  
  for (int i = 0; i < steps; i++) {
    digitalWrite(CCW, HIGH);
    delayMicroseconds(3600);
    digitalWrite(CCW, LOW);
    delayMicroseconds(3600);
  }
}

void setup() {
  pinMode(CW, OUTPUT);
  pinMode(CCW, OUTPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT_PULLUP);
  pinMode(LEFT_SENSOR_PIN, INPUT_PULLUP);
}

void loop() {
  while (digitalRead(RIGHT_SENSOR_PIN) == HIGH) {
    // Rotating CCW until right sensor is interrupted
    rotateCCW(5); // Rotating by a small angle
  }
  delay(200); // delay for stability

  while (digitalRead(LEFT_SENSOR_PIN) == HIGH) {
    // Rotating CW until left sensor is interrupted
    rotateCW(5); // Rotating by a small angle
  }
  delay(200); // Waiting for stability
}
