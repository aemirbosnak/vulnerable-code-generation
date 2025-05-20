//FormAI DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lights = 0;
int thermostat = 0;
int tv = 0;

void turnOn(char* device);
void turnOff(char* device);
void tempUp();
void tempDown();
void showStatus();

int main() {
  char input[100];

  while (1) {
    printf("Enter command: ");
    scanf("%s", input);

    if (strcmp(input, "lights-on") == 0)
      turnOn("lights");
    else if (strcmp(input, "lights-off") == 0)
      turnOff("lights");
    else if (strcmp(input, "thermostat-up") == 0)
      tempUp();
    else if (strcmp(input, "thermostat-down") == 0)
      tempDown();
    else if (strcmp(input, "tv-on") == 0)
      turnOn("tv");
    else if (strcmp(input, "tv-off") == 0)
      turnOff("tv");
    else if (strcmp(input, "status") == 0)
      showStatus();
    else
      printf("Invalid command.\n");
  }

  return 0;
}

void turnOn(char* device) {
  if (strcmp(device, "lights") == 0) {
    lights = 1;
    printf("Lights turned on.\n");
  }
  else if (strcmp(device, "tv") == 0) {
    tv = 1;
    printf("TV turned on.\n");
  }
}

void turnOff(char* device) {
  if (strcmp(device, "lights") == 0) {
    lights = 0;
    printf("Lights turned off.\n");
  }
  else if (strcmp(device, "tv") == 0) {
    tv = 0;
    printf("TV turned off.\n");
  }
}

void tempUp() {
  if (thermostat < 90) {
    thermostat++;
    printf("Temperature raised to %d degrees.\n", thermostat);
  }
  else
    printf("Temperature cannot be raised any further.\n");
}

void tempDown() {
  if (thermostat > 60) {
    thermostat--;
    printf("Temperature lowered to %d degrees.\n", thermostat);
  }
  else
    printf("Temperature cannot be lowered any further.\n");
}

void showStatus() {
  printf("Lights: %s\n", lights ? "On" : "Off");
  printf("TV: %s\n", tv ? "On" : "Off");
  printf("Temperature: %d degrees\n", thermostat);
}