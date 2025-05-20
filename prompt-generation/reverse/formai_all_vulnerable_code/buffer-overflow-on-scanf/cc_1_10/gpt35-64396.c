//FormAI DATASET v1.0 Category: Smart home automation ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>

// function declarations
void lightOn(bool lightState[]);
void lightOff(bool lightState[]);
void fanOn(bool fanState[]);
void fanOff(bool fanState[]);
void doorLock(bool doorState[]);
void doorUnlock(bool doorState[]);

int main() {
  // initialize the device states
  bool lightState = false;
  bool fanState = false;
  bool doorState = false;

  // welcome message
  printf("Welcome to your Smart Home Automation System!\n");

  // loop the program until the user exits
  while (true) {
    // print menu
    printf("\nPlease choose an option:\n");
    printf("1. Turn lights on/off\n");
    printf("2. Turn fans on/off\n");
    printf("3. Lock/Unlock doors\n");
    printf("4. Exit\n");

    // get user input
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: // lights
        if (lightState) {
          lightOff(&lightState);
        } else {
          lightOn(&lightState);
        }
        break;
      case 2: // fans
        if (fanState) {
          fanOff(&fanState);
        } else {
          fanOn(&fanState);
        }
        break;
      case 3: // doors
        if (doorState) {
          doorUnlock(&doorState);
        } else {
          doorLock(&doorState);
        }
        break;
      case 4: // exit
        printf("\nThank you for using Smart Home Automation System!\n");
        return 0;
      default:
        printf("\nInvalid input. Please try again.\n");
        break;
    }
  }
}

void lightOn(bool lightState[]) {
  *lightState = true;
  printf("\nLights turned on.\n");
}

void lightOff(bool lightState[]) {
  *lightState = false;
  printf("\nLights turned off.\n");
}

void fanOn(bool fanState[]) {
  *fanState = true;
  printf("\nFans turned on.\n");
}

void fanOff(bool fanState[]) {
  *fanState = false;
  printf("\nFans turned off.\n");
}

void doorLock(bool doorState[]) {
  *doorState = true;
  printf("\nDoors locked.\n");
}

void doorUnlock(bool doorState[]) {
  *doorState = false;
  printf("\nDoors unlocked.\n");
}