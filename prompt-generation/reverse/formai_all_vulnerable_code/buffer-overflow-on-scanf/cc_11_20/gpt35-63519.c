//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

  int batteryLevel = 100;
  bool isFlying = false;
  bool batteryWarning = false;

  printf("Welcome to C Drone Remote Control\n\n");

  while (true) {
    printf("Please select an option:\n");
    printf("1. Take off\n");
    printf("2. Land\n");
    printf("3. Go left\n");
    printf("4. Go right\n");
    printf("5. Go forward\n");
    printf("6. Go backward\n");

    int command;
    scanf("%d", &command);

    switch(command) {
      case 1:
        if (!isFlying) {
          isFlying = true;
          printf("The drone is taking off...\n");
        } else {
          printf("The drone is already flying...\n");
        }
        break;

      case 2:
        if (isFlying) {
          isFlying = false;
          printf("The drone is landing...\n");
        } else {
          printf("The drone is already landed...\n");
        }
        break;

      case 3:
        if (isFlying) {
          printf("The drone is moving left...\n");
        } else {
          printf("The drone needs to be in the air to move left...\n");
        }
        break;

      case 4:
        if (isFlying) {
          printf("The drone is moving right...\n");
        } else {
          printf("The drone needs to be in the air to move right...\n");
        }
        break;

      case 5:
        if (isFlying) {
          printf("The drone is moving forward...\n");
        } else {
          printf("The drone needs to be in the air to move forward...\n");
        }
        break;

      case 6:
        if (isFlying) {
          printf("The drone is moving backward...\n");
        } else {
          printf("The drone needs to be in the air to move backward...\n");
        }
        break;

      default:
        printf("Invalid command. Please try again...\n");
        break;
    }

    if (isFlying && batteryLevel <= 10) {
      if (!batteryWarning) {
        printf("*** Battery level low! ***\n");
        batteryWarning = true;
      }
    } else {
      batteryWarning = false;
    }

    if (batteryLevel <= 0) {
      printf("*** Drone has run out of power and has crashed! ***\n");
      break;
    }

    int batteryUsage = rand() % 5 + 1;
    batteryLevel -= batteryUsage;

    printf("Battery level: %d%%\n", batteryLevel);

    // Sleep for 1 second
    sleep(1);
  }

  return 0;
}