//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOOR 10

typedef struct Elevator {
  int currentFloor;
  int direction;
  int passengers;
} Elevator;

int main() {

  Elevator elevator;
  elevator.currentFloor = 1;
  elevator.direction = 0;
  elevator.passengers = 0;

  int targetFloor;

  // Loop until the target floor is selected
  while (1) {
    printf("Enter target floor (1-10): ");
    scanf("%d", &targetFloor);

    // Check if the target floor is valid
    if (targetFloor < 1 || targetFloor > MAX_FLOOR) {
      printf("Invalid target floor.\n");
      continue;
    }

    // Calculate the direction of travel
    if (targetFloor > elevator.currentFloor) {
      elevator.direction = 1;
    } else if (targetFloor < elevator.currentFloor) {
      elevator.direction = -1;
    } else {
      printf("Already at target floor.\n");
      continue;
    }

    // Simulate elevator movement
    sleep(2);
    elevator.currentFloor += elevator.direction;

    // Print the current floor
    printf("Current floor: %d\n", elevator.currentFloor);

    // Check if the elevator has reached the target floor
    if (elevator.currentFloor == targetFloor) {
      printf("Doors opening.\n");
      elevator.passengers = 0;
      break;
    }
  }

  return 0;
}