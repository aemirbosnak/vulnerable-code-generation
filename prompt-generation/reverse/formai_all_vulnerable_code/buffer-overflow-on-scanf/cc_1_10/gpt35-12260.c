//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initializing variables
  int pitch = 0;
  int roll = 0;
  int altitude = 0;
  int yaw = 0;
  int speed = 50;

  // Starting the drone
  printf("Starting the drone...\n");
  printf("Drone ready to fly\n");

  // Loop to keep the drone running until the user stops it
  while (1) {
    // Getting the user's input
    printf("Enter pitch (-100 to 100): ");
    scanf("%d", &pitch);

    printf("Enter roll (-100 to 100): ");
    scanf("%d", &roll);

    printf("Enter altitude (0 to 100): ");
    scanf("%d", &altitude);

    printf("Enter yaw (-180 to 180): ");
    scanf("%d", &yaw);

    printf("Enter speed (0 to 100): ");
    scanf("%d", &speed);

    // Printing the drone's status
    printf("\tPitch: %d\n", pitch);
    printf("\tRoll: %d\n", roll);
    printf("\tAltitude: %d\n", altitude);
    printf("\tYaw: %d\n", yaw);
    printf("\tSpeed: %d\n", speed);
    printf("\n");

    // Checking if the user wants to stop the drone
    char stop_drone;
    printf("Do you want to stop the drone? (y/n) ");
    scanf(" %c", &stop_drone);
    if (stop_drone == 'y') {
      printf("Stopping the drone...\n");
      break;
    }
  }

  // Shutting down the drone
  printf("Drone has been shut down.\n");

  return 0;
}