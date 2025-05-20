//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the number of floors
#define NUM_FLOORS 5

// Define the elevator floor number
int currentFloor = 1;

// Define the elevator direction
enum Direction { UP, DOWN };

// Define the elevator state
enum State { IDLE, MOVING, STOPPED };

// Global variables
int targetFloor;
enum Direction direction;
enum State state;

void moveElevator() {
  // Calculate the number of floors to move
  int floorsToMove = abs(targetFloor - currentFloor);

  // Move the elevator up or down
  switch (direction) {
    case UP:
      currentFloor++;
      break;
    case DOWN:
      currentFloor--;
      break;
  }

  // Stop the elevator
  state = STOPPED;
}

void displayFloor() {
  // Display the current floor
  printf("Current floor: %d\n", currentFloor);
}

int main() {
  // Initialize the elevator state
  state = IDLE;

  // Get the target floor
  printf("Enter target floor: ");
  scanf("%d", &targetFloor);

  // Set the direction
  if (targetFloor > currentFloor) {
    direction = UP;
  } else if (targetFloor < currentFloor) {
    direction = DOWN;
  }

  // Start the elevator moving
  moveElevator();

  // Display the current floor
  displayFloor();

  return 0;
}