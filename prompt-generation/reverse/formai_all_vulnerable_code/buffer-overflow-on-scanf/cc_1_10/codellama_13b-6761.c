//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: unmistakable
/*
 * Elevator Simulation
 *
 * This program simulates the operation of an elevator in a building.
 * It accepts a floor number as input, and moves the elevator to that floor.
 * If the elevator is already on that floor, it does nothing.
 * If the elevator is moving to a different floor, it moves at a constant speed
 * until it reaches the requested floor.
 */

#include <stdio.h>

// Constants
#define MAX_FLOORS 10
#define MAX_ELEVATORS 5
#define ELEVATOR_SPEED 1

// Data types
struct elevator {
  int floor;
  int direction;
  int speed;
};

// Function prototypes
void move_elevator(struct elevator *elevator, int floor);

int main() {
  // Initialize elevators
  struct elevator elevators[MAX_ELEVATORS];
  for (int i = 0; i < MAX_ELEVATORS; i++) {
    elevators[i].floor = 0;
    elevators[i].direction = 0;
    elevators[i].speed = ELEVATOR_SPEED;
  }

  // Accept input
  int floor;
  printf("Enter floor number: ");
  scanf("%d", &floor);

  // Move elevator to requested floor
  move_elevator(&elevators[0], floor);

  // Print elevator status
  printf("Elevator status:\n");
  for (int i = 0; i < MAX_ELEVATORS; i++) {
    printf("  Elevator %d: floor %d\n", i, elevators[i].floor);
  }

  return 0;
}

void move_elevator(struct elevator *elevator, int floor) {
  // Check if elevator is already on requested floor
  if (elevator->floor == floor) {
    return;
  }

  // Move elevator to requested floor
  if (elevator->floor > floor) {
    elevator->direction = -1;
  } else {
    elevator->direction = 1;
  }
  elevator->floor += elevator->direction * elevator->speed;
}