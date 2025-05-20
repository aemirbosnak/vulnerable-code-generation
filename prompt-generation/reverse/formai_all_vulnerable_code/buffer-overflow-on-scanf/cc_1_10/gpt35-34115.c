//FormAI DATASET v1.0 Category: Smart home automation ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>

// Function to turn on lights
void turnOnLights() {
  printf("Lights turned on!\n");
}

// Function to turn off lights
void turnOffLights() {
  printf("Lights turned off!\n");
}

// Function to lock doors
void lockDoors() {
  printf("Doors locked!\n");
}

// Function to unlock doors
void unlockDoors() {
  printf("Doors unlocked!\n");
}

// Main function
int main() {
  bool lightsOn = false;
  bool doorsLocked = true;

  printf("Welcome to Smart Home Automation System\n");

  while (true) {
    printf("What would you like to do?\n");
    printf("  1. Turn lights on/off\n");
    printf("  2. Lock/unlock doors\n");
    printf("  3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (lightsOn) {
          turnOffLights();
          lightsOn = false;
        } else {
          turnOnLights();
          lightsOn = true;
        }
        break;

      case 2:
        if (doorsLocked) {
          unlockDoors();
          doorsLocked = false;
        } else {
          lockDoors();
          doorsLocked = true;
        }
        break;

      case 3:
        printf("Thank you for using Smart Home Automation System\n");
        return 0;

      default:
        printf("Invalid choice!\n");
        break;
    }
  }
}