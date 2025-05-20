//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int floors;
  int people;
  int currentFloor;
  int nextMove;
} Elevator;

Elevator createElevator() {
  Elevator e;
  e.floors = 10;
  e.people = 0;
  e.currentFloor = 0;
  e.nextMove = -1;
  return e;
}

int main() {
  Elevator e = createElevator();

  printf("Press 1 for going up \n");
  printf("Press 2 for going down \n");
  printf("Press 3 for stop \n");
  
  int choice;
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      if (e.currentFloor < e.floors) {
        e.currentFloor++;
      }
      break;
    case 2:
      if (e.currentFloor > 0) {
        e.currentFloor--;
      }
      break;
    case 3:
      break;
    default:
      printf("Invalid input");
  }

  printf("Current floor: %d \n", e.currentFloor);

  return 0;
}