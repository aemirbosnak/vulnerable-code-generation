//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 10

struct Elevator {
  int currentFloor;
  int destinationFloor;
  int passengers[MAX_PASSENGERS];
  int numPassengers;
};

void printElevator(struct Elevator *elevator) {
  printf("Elevator: ");
  if (elevator->numPassengers > 0) {
    for (int i = 0; i < elevator->numPassengers; i++) {
      printf("%d ", elevator->passengers[i]);
    }
  } else {
    printf("empty");
  }
  printf("\n");
}

void moveElevator(struct Elevator *elevator, int floor) {
  elevator->currentFloor = floor;
}

void callElevator(struct Elevator *elevator, int floor) {
  elevator->destinationFloor = floor;
}

void addPassenger(struct Elevator *elevator, int floor) {
  if (elevator->numPassengers < MAX_PASSENGERS) {
    elevator->passengers[elevator->numPassengers] = floor;
    elevator->numPassengers++;
  } else {
    printf("Elevator is full!\n");
  }
}

void removePassenger(struct Elevator *elevator, int floor) {
  for (int i = 0; i < elevator->numPassengers; i++) {
    if (elevator->passengers[i] == floor) {
      elevator->passengers[i] = -1;
      elevator->numPassengers--;
      return;
    }
  }
}

int main() {
  struct Elevator elevator;
  elevator.currentFloor = 0;
  elevator.destinationFloor = 0;
  elevator.numPassengers = 0;

  for (int i = 0; i < MAX_FLOORS; i++) {
    printf("Floor %d: ", i);
    printElevator(&elevator);
    int action;
    printf("Enter action (call, add, remove): ");
    scanf("%d", &action);
    if (action == 0) {
      callElevator(&elevator, i);
    } else if (action == 1) {
      addPassenger(&elevator, i);
    } else if (action == 2) {
      removePassenger(&elevator, i);
    }
    moveElevator(&elevator, i);
  }

  return 0;
}