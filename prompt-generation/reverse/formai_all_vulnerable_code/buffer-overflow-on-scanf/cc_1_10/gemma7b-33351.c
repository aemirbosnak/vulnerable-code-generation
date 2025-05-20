//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 5
#define BUTTONS_PER_FLOOR 2

typedef struct Elevator {
  int currentFloor;
  int direction;
  int passengers;
  struct Elevator *next;
} Elevator;

void simulateElevator(Elevator *elevator) {
  int destinationFloor;

  // Get the destination floor from the user
  printf("Enter your destination floor (1-5): ");
  scanf("%d", &destinationFloor);

  // Check if the elevator is moving in the right direction
  if (elevator->direction == destinationFloor - elevator->currentFloor) {
    // The elevator is already moving in the right direction, so just go to the destination floor
    elevator->currentFloor = destinationFloor;
  } else {
    // The elevator is not moving in the right direction, so change direction and go to the destination floor
    elevator->direction = destinationFloor - elevator->currentFloor;
    elevator->currentFloor = destinationFloor;
  }

  // Print the elevator's current floor
  printf("The elevator is now on floor %d.\n", elevator->currentFloor);
}

int main() {
  Elevator *elevator = NULL;

  // Create a new elevator
  elevator = malloc(sizeof(Elevator));
  elevator->currentFloor = 1;
  elevator->direction = 0;
  elevator->passengers = 0;
  elevator->next = NULL;

  // Simulate the elevator
  simulateElevator(elevator);

  // Free the elevator
  free(elevator);

  return 0;
}