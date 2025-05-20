//FormAI DATASET v1.0 Category: Smart home automation ; Style: relaxed
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to Smart Home Automation\n");

  // Declarations
  int temperature;
  int humidity;
  int light_sensor;
  int motion_sensor;

  // User input
  printf("Enter current temperature: ");
  scanf("%d", &temperature);
  printf("Enter current humidity: ");
  scanf("%d", &humidity);
  printf("Enter light sensor reading: ");
  scanf("%d", &light_sensor);
  printf("Enter motion sensor reading: ");
  scanf("%d", &motion_sensor);

  // Temperature control
  if (temperature > 25) {
    printf("Turning on air conditioning...\n");
  } else if (temperature < 20) {
    printf("Turning on heater...\n");
  } else {
    printf("Temperature is within range...\n");
  }

  // Humidity control
  if (humidity > 70) {
    printf("Turning on dehumidifier...\n");
  } else if (humidity < 40) {
    printf("Turning on humidifier...\n");
  } else {
    printf("Humidity is within range...\n");
  }

  // Light control
  if (light_sensor < 50) {
    printf("Turning on lights...\n");
  } else {
    printf("Lights are already on...\n");
  }

  // Security control
  if (motion_sensor > 0) {
    printf("Sending notification to owners...\n");
  }

  // Farewell message
  printf("Thank you for using Smart Home Automation\n");

  return 0;
}