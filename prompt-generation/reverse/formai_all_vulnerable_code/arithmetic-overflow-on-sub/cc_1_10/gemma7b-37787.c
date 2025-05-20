//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10

typedef struct Elevator {
  int currentFloor;
  int destinationFloor;
  int passengers;
  int direction;
  struct Elevator *next;
} Elevator;

void simulateElevator(Elevator *elevator) {
  time_t t;
  int i;

  t = time(NULL);
  printf("Elevator Simulation - Start Time: %s\n",ctime(t));

  while (elevator->currentFloor != elevator->destinationFloor) {
    printf("Current Floor: %d, Destination Floor: %d, Passengers: %d\n", elevator->currentFloor, elevator->destinationFloor, elevator->passengers);

    switch (elevator->direction) {
      case 0:
        elevator->currentFloor++;
        break;
      case 1:
        elevator->currentFloor--;
        break;
    }

    printf("Time Elapsed: %d seconds\n", time(NULL) - t);
    t = time(NULL);

    for (i = 0; i < elevator->passengers; i++) {
      printf("Passenger %d is exiting the elevator on floor %d\n", i + 1, elevator->currentFloor);
    }

    elevator->passengers = 0;
  }

  t = time(NULL);
  printf("Elevator Simulation - End Time: %s\n",ctime(t));
}

int main() {
  Elevator *elevator = malloc(sizeof(Elevator));
  elevator->currentFloor = 1;
  elevator->destinationFloor = 5;
  elevator->passengers = 3;
  elevator->direction = 0;

  simulateElevator(elevator);

  return 0;
}