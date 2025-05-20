//FormAI DATASET v1.0 Category: Smart home automation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int temperature = 0;
  int humidity = 0;
  int lightStatus = 0;
  int motionStatus = 0;

  // Get environmental readings from sensors
  printf("Reading data from sensors...\n");
  printf("Enter the current temperature: ");
  scanf("%d", &temperature);
  printf("Enter the current humidity: ");
  scanf("%d", &humidity);
  printf("Is the light on or off? (Enter 1 for on, 0 for off): ");
  scanf("%d", &lightStatus);
  printf("Is there motion detected? (Enter 1 for detected, 0 for not detected): ");
  scanf("%d", &motionStatus);

  // Check temperature and turn on/off the air conditioner
  if (temperature > 25) {
    printf("Temperature is too high! Turning on the air conditioner...\n");
    // Code for turning on air conditioner goes here
  } else {
    printf("Temperature is normal.\n");
    // Code for turning off air conditioner goes here
  }

  // Check humidity and turn on/off the humidifier
  if (humidity < 40) {
    printf("Humidity is too low! Turning on the humidifier...\n");
    // Code for turning on the humidifier goes here
  } else {
    printf("Humidity is normal.\n");
    // Code for turning off the humidifier goes here
  }

  // Check light status and adjust brightness
  if (lightStatus == 1) {
    printf("Light is on. Adjusting brightness...\n");
    // Code for adjusting light brightness goes here
  } else {
    printf("Light is off.\n");
  }

  // Check motion status and send alert to smartphone
  if (motionStatus == 1) {
    printf("Motion detected! Sending alert to smartphone...\n");
    // Code for sending alert to smartphone goes here
  } else {
    printf("No motion detected.\n");
  }

  return 0;
}