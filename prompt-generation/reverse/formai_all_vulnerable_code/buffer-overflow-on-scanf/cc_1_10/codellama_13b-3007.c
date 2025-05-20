//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FLOORS 10
#define MAX_ELEVATORS 5

typedef struct {
  int current_floor;
  int destination_floor;
  int speed;
} Elevator;

void move_elevators(Elevator *elevators, int num_elevators, int num_floors) {
  for (int i = 0; i < num_elevators; i++) {
    Elevator *elevator = &elevators[i];
    if (elevator->current_floor != elevator->destination_floor) {
      if (elevator->current_floor < elevator->destination_floor) {
        elevator->current_floor++;
      } else {
        elevator->current_floor--;
      }
    }
  }
}

void request_elevator(Elevator *elevators, int num_elevators, int num_floors, int floor) {
  for (int i = 0; i < num_elevators; i++) {
    Elevator *elevator = &elevators[i];
    if (elevator->destination_floor == -1) {
      elevator->destination_floor = floor;
      break;
    }
  }
}

int main() {
  Elevator elevators[MAX_ELEVATORS];
  for (int i = 0; i < MAX_ELEVATORS; i++) {
    elevators[i].current_floor = 0;
    elevators[i].destination_floor = -1;
    elevators[i].speed = 1;
  }

  int num_floors = NUM_FLOORS;
  int num_elevators = MAX_ELEVATORS;

  while (1) {
    move_elevators(elevators, num_elevators, num_floors);

    int floor;
    printf("Enter floor: ");
    scanf("%d", &floor);

    request_elevator(elevators, num_elevators, num_floors, floor);

    for (int i = 0; i < num_elevators; i++) {
      Elevator *elevator = &elevators[i];
      if (elevator->destination_floor == floor) {
        printf("Elevator %d is at floor %d\n", i, floor);
      }
    }
  }

  return 0;
}