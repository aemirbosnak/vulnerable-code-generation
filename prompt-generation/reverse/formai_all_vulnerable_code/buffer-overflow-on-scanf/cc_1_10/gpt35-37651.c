//FormAI DATASET v1.0 Category: Smart home automation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to turn on the lights
void turnOnLights() {
  printf("Lights turned ON.\n");
}

// Function to turn off the lights
void turnOffLights() {
  printf("Lights turned OFF.\n");
}

// Function to turn on the air conditioner
void turnOnAC() {
  printf("Air Conditioner turned ON.\n");
}

// Function to turn off the air conditioner
void turnOffAC() {
  printf("Air Conditioner turned OFF.\n");
}

int main() {
  int temperature, lightStatus, acStatus;
  printf("Welcome to the Smart Home Automation Program!\n");
  printf("Please enter the current room temperature: ");
  scanf("%d", &temperature);
  if (temperature > 30) {
    // Turn on the air conditioner if the temperature is high
    turnOnAC();
    acStatus = 1;
  } else {
    // Turn off the air conditioner if the temperature is low
    turnOffAC();
    acStatus = 0;
  }
  printf("Please enter the current status of the lights (1 = ON, 0 = OFF): ");
  scanf("%d", &lightStatus);
  if (lightStatus == 0 && acStatus == 1) {
    // If the lights are off and the AC is on, turn the lights on
    turnOnLights();
  } else if (lightStatus == 1 && acStatus == 0) {
    // If the lights are on and the AC is off, turn the lights off
    turnOffLights();
  } else if (lightStatus == 0 && acStatus == 0) {
    // If both the lights and AC are off, turn the lights on and the AC off
    turnOnLights();
    turnOffAC();
  }
  printf("Thank you for using the Smart Home Automation Program!\n");
  return 0;
}