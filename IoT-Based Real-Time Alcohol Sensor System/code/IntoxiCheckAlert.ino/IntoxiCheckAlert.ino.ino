#define sensorDigital 2
#define LED 3
#define buzzer 4
#define sensorAnalog A1
void setup() {
pinMode(sensorDigital, INPUT);
pinMode(LED, OUTPUT);
pinMode(buzzer, OUTPUT);
Serial.begin(9600);
}
void loop() {
bool digital = digitalRead(sensorDigital);
int analog = analogRead(sensorAnalog);
Serial.print("Analog value: ");
Serial.print(analog);
Serial.print("\t");
Serial.print("Digital value: ");
Serial.print(digital);
Serial.print("\t");
// Estimate alcohol level category
String alcoholLevel;
if (analog < 200) {
alcoholLevel = "Low";
} else if (analog < 400) {
alcoholLevel = "Moderate";
29
} else {
alcoholLevel = "High";
}
Serial.print("Estimated Alcohol Level: ");
Serial.println(alcoholLevel);
// Alert using LED and buzzer if alcohol detected
if (digital == 0) {
digitalWrite(LED, HIGH);
digitalWrite(buzzer, HIGH);
} else {
digitalWrite(LED, LOW);
digitalWrite(buzzer, LOW);
}
delay(1000); // Add delay for readability
}