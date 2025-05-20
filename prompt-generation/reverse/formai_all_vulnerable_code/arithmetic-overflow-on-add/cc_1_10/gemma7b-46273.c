//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef struct elevator {
  int currentFloor;
  int targetFloor;
  int passengers;
  int direction;
} elevator;

elevator createElevator() {
  elevator elevator;
  elevator.currentFloor = 1;
  elevator.targetFloor = 1;
  elevator.passengers = 0;
  elevator.direction = 0;
  return elevator;
}

void moveElevator(elevator *elevator) {
  int floorsToGo;
  if (elevator->direction == 0) {
    floorsToGo = elevator->targetFloor - elevator->currentFloor;
    if (floorsToGo > 0) {
      elevator->direction = 1;
    } else if (floorsToGo < 0) {
      elevator->direction = -1;
    }
  }

  elevator->currentFloor += elevator->direction * floorsToGo;
  printf("Elevator is on floor %d.\n", elevator->currentFloor);
}

int main() {
  elevator elevator = createElevator();

  elevator.targetFloor = 5;
  moveElevator(&elevator);

  elevator.targetFloor = 3;
  moveElevator(&elevator);

  elevator.targetFloor = 8;
  moveElevator(&elevator);

  return 0;
}