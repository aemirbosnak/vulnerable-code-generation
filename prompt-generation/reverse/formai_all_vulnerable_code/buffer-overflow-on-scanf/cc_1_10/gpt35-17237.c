//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define variables to store drone parameters
int droneSpeed = 0;
int droneHeight = 0;
bool droneIsFlying = false;

// Define function to fly the drone
void flyDrone() {
  droneIsFlying = true;
  printf("Drone is now flying\n");
}

// Define function to land the drone
void landDrone() {
  droneIsFlying = false;
  droneHeight = 0;
  printf("Drone has landed\n");
}

// Define function to increase the speed of the drone
void increaseDroneSpeed() {
  if (droneSpeed < 100) {
    droneSpeed += 10;
    printf("Drone speed increased to %d\n", droneSpeed);
  }
}

// Define function to decrease the speed of the drone
void decreaseDroneSpeed() {
  if (droneSpeed > 0) {
    droneSpeed -= 10;
    printf("Drone speed decreased to %d\n", droneSpeed);
  }
}

// Define function to increase the height of the drone
void increaseDroneHeight() {
  droneHeight += 10;
  printf("Drone height increased to %d\n", droneHeight);
}

// Define function to decrease the height of the drone
void decreaseDroneHeight() {
  if (droneHeight > 0) {
    droneHeight -= 10;
    printf("Drone height decreased to %d\n", droneHeight);
  }
}

int main() {
  int userChoice = 0;

  // Display menu options to user
  printf("Welcome to the drone remote control program!\n");
  printf("--------------------------------------------\n");

  while (userChoice != 6) {
    printf("\nPlease select an option:\n");
    printf("1. Fly the drone\n");
    printf("2. Land the drone\n");
    printf("3. Increase speed\n");
    printf("4. Decrease speed\n");
    printf("5. Adjust height\n");
    printf("6. Quit\n\n");

    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &userChoice);

    // Handle user selection
    switch (userChoice) {
      case 1:
        if (!droneIsFlying) {
          flyDrone();
        }
        else {
          printf("Drone is already flying\n");
        }
        break;
      case 2:
        if (droneIsFlying) {
          landDrone();
        }
        else {
          printf("Drone is already landed\n");
        }
        break;
      case 3:
        increaseDroneSpeed();
        break;
      case 4:
        decreaseDroneSpeed();
        break;
      case 5:
        if (!droneIsFlying) {
          printf("Cannot adjust height while drone is landed\n");
        }
        else {
          int heightChoice = 0;
          printf("Enter 1 to increase height or 2 to decrease height: ");
          scanf("%d", &heightChoice);
          switch (heightChoice) {
            case 1:
              increaseDroneHeight();
              break;
            case 2:
              decreaseDroneHeight();
              break;
            default:
              printf("Invalid choice\n");
          }
        }
        break;
      case 6:
        printf("Quitting...\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}