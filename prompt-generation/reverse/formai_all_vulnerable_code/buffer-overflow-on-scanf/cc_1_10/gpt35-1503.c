//FormAI DATASET v1.0 Category: Smart home automation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to turn on/off the lights
void toggleLights(int state) {
  if (state == 1) {
    printf("Turning on the lights\n");
  } else {
    printf("Turning off the lights\n");
  }
}

// Function to adjust the room temperature
void adjustTemperature(int temp) {
  printf("Adjusting temperature to %d degrees\n", temp);
}

// Function to unlock/lock doors
void toggleDoors(int state) {
  if (state == 1) {
    printf("Unlocking the doors\n");
  } else {
    printf("Locking the doors\n");
  }
}

int main() {
  int lightState = 0; // 0 = off, 1 = on
  int temperature = 24; // starting room temperature
  int doorState = 0; // 0 = locked, 1 = unlocked

  printf("Welcome to the Smart Home Automation System\n");

  // Loop the system until user quits
  while (1) {
    int choice = 0;

    printf("\nPlease select an option:\n");
    printf("1. Turn on/off lights\n");
    printf("2. Adjust room temperature\n");
    printf("3. Lock/unlock doors\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    if (choice == 1) {
      lightState = !lightState; // toggle lights
      toggleLights(lightState);
    } else if (choice == 2) {
      printf("Enter desired temperature:\n");
      scanf("%d", &temperature);
      adjustTemperature(temperature);
    } else if (choice == 3) {
      doorState = !doorState; // toggle doors
      toggleDoors(doorState);
    } else if (choice == 4) {
      printf("Goodbye!\n");
      break; // exit loop
    } else {
      printf("Invalid choice, try again!\n");
    }
  }

  return 0;
}