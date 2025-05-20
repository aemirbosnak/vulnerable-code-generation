//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define constants for vehicle movement
#define MOVE_FORWARD 1
#define MOVE_BACKWARD -1
#define TURN_LEFT 2
#define TURN_RIGHT -2

int main() {
  int vehicleDirection = 0; // The vehicle's initial direction is not moving
  int vehiclePositionX = 0; // The vehicle's initial x position is 0
  int vehiclePositionY = 0; // The vehicle's initial y position is 0

  printf("Welcome to RC Vehicle Simulation\n");

  while(1) { // Infinite loop until program is exited
    char userInput;

    // Prompt user for vehicle movement
    printf("\nEnter a movement command for the vehicle:\n");
    printf("W - Move Forward\n");
    printf("S - Move Backward\n");
    printf("A - Turn Left\n");
    printf("D - Turn Right\n");
    printf("X - Exit Program\n");
    scanf(" %c", &userInput);

    // Handle user input
    switch(userInput) {
      case 'W':
        vehicleDirection = MOVE_FORWARD;
        break;
      case 'S':
        vehicleDirection = MOVE_BACKWARD;
        break;
      case 'A':
        vehicleDirection = TURN_LEFT;
        break;
      case 'D':
        vehicleDirection = TURN_RIGHT;
        break;
      case 'X':
        printf("\nExiting RC Vehicle Simulation\n");
        exit(0);
      default:
        printf("\nInvalid input\n");
        continue;
    }

    // Update vehicle position based on direction and movement
    if(vehicleDirection == MOVE_FORWARD) {
      vehiclePositionY++;
    } else if(vehicleDirection == MOVE_BACKWARD) {
      vehiclePositionY--;
    } else if(vehicleDirection == TURN_LEFT) {
      vehiclePositionX--;
    } else if(vehicleDirection == TURN_RIGHT) {
      vehiclePositionX++;
    }

    // Print updated vehicle position and direction
    printf("Vehicle Position: (%d, %d)\n", vehiclePositionX, vehiclePositionY);

    if(vehicleDirection == MOVE_FORWARD || vehicleDirection == MOVE_BACKWARD) {
      printf("Vehicle Direction: ");
      for(int i = 0; i < vehiclePositionX; i++) {
        printf(" ");
      }
      if(vehicleDirection == MOVE_FORWARD) {
        printf("^");
      } else {
        printf("V");
      }
    } else {
      printf("Vehicle Direction: ");
      for(int i = 0; i < vehiclePositionX; i++) {
        printf(" ");
      }
      if(vehicleDirection == TURN_LEFT) {
        printf("<");
      } else {
        printf(">");
      }
    }
  }

  return 0;
}