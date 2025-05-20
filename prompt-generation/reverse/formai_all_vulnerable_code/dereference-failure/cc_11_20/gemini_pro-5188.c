//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int floor;
  int destination;
  int time;
} Passenger;

typedef struct {
  int current_floor;
  int direction;
  Passenger* passengers[10];
  int num_passengers;
} Elevator;

int main() {
  srand(time(NULL));

  // Create the elevator
  Elevator elevator = {0, 0, {NULL}, 0};

  // Create a random number of passengers
  int num_passengers = rand() % 10;

  // Create the passengers
  for (int i = 0; i < num_passengers; i++) {
    Passenger* passenger = malloc(sizeof(Passenger));
    passenger->floor = rand() % 10;
    passenger->destination = rand() % 10;
    passenger->time = rand() % 10;
    elevator.passengers[i] = passenger;
    elevator.num_passengers++;
  }

  // Simulate the elevator
  while (elevator.num_passengers > 0) {
    // Move the elevator
    if (elevator.direction == 0) {
      elevator.current_floor++;
    } else {
      elevator.current_floor--;
    }

    // Check if any passengers need to get off
    for (int i = 0; i < elevator.num_passengers; i++) {
      if (elevator.passengers[i]->destination == elevator.current_floor) {
        free(elevator.passengers[i]);
        elevator.passengers[i] = NULL;
        elevator.num_passengers--;
      }
    }

    // Check if any passengers need to get on
    for (int i = 0; i < num_passengers; i++) {
      if (elevator.passengers[i] == NULL && elevator.current_floor == elevator.passengers[i]->floor) {
        elevator.passengers[i] = malloc(sizeof(Passenger));
        elevator.passengers[i]->floor = elevator.current_floor;
        elevator.passengers[i]->destination = rand() % 10;
        elevator.passengers[i]->time = rand() % 10;
        elevator.num_passengers++;
      }
    }

    // Change the direction of the elevator if necessary
    if (elevator.current_floor == 0) {
      elevator.direction = 1;
    } else if (elevator.current_floor == 9) {
      elevator.direction = 0;
    }
  }

  return 0;
}