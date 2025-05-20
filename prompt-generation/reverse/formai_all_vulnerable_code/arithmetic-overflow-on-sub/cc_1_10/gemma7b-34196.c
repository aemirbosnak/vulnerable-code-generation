//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct Elevator {
  int currentFloor;
  int destinationFloor;
  int numPassengers;
  int direction;
  struct Elevator *next;
} Elevator;

void simulateElevator(Elevator *elevator) {
  time_t start, end;
  start = time(NULL);

  while (elevator->currentFloor != elevator->destinationFloor) {
    int currentFloor = elevator->currentFloor;
    elevator->currentFloor += elevator->direction;

    if (elevator->numPassengers > 0) {
      printf("Elevator at floor %d with %d passengers.\n", currentFloor, elevator->numPassengers);
    } else {
      printf("Elevator at floor %d.\n", currentFloor);
    }

    end = time(NULL);
    printf("Time taken to reach floor %d: %f seconds.\n", elevator->destinationFloor, (double)(end - start) / CLOCKS_PER_SEC);

    sleep(1);
  }

  elevator->numPassengers = 0;
  elevator->currentFloor = 0;
}

int main() {
  Elevator *elevator = malloc(sizeof(Elevator));
  elevator->currentFloor = 1;
  elevator->destinationFloor = 5;
  elevator->numPassengers = 2;
  elevator->direction = 1;

  simulateElevator(elevator);

  free(elevator);

  return 0;
}