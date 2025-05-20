//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: modular
/*
 * Elevator Simulation Example Program
 *
 * Written in a modular style
 */

#include <stdio.h>

// Define constants
#define MAX_FLOORS 10
#define MAX_ELEVATORS 5

// Define data structures
typedef struct {
  int current_floor;
  int destination_floor;
  int is_moving;
  int is_door_open;
} Elevator;

// Define functions
void move_elevator(Elevator *elevator) {
  // Check if elevator is moving
  if (elevator->is_moving) {
    // Check if elevator has reached its destination
    if (elevator->current_floor == elevator->destination_floor) {
      elevator->is_moving = 0;
      elevator->is_door_open = 1;
    } else {
      // Move elevator up or down
      if (elevator->current_floor < elevator->destination_floor) {
        elevator->current_floor++;
      } else {
        elevator->current_floor--;
      }
    }
  }
}

void open_door(Elevator *elevator) {
  // Check if elevator is moving
  if (!elevator->is_moving) {
    elevator->is_door_open = 1;
  }
}

void close_door(Elevator *elevator) {
  // Check if elevator is moving
  if (!elevator->is_moving) {
    elevator->is_door_open = 0;
  }
}

void print_elevator_status(Elevator *elevator) {
  printf("Elevator %d: Floor %d, Door %s\n", elevator->current_floor, elevator->is_door_open ? "Open" : "Closed");
}

int main() {
  // Initialize elevators
  Elevator elevators[MAX_ELEVATORS];
  for (int i = 0; i < MAX_ELEVATORS; i++) {
    elevators[i].current_floor = 1;
    elevators[i].destination_floor = 1;
    elevators[i].is_moving = 0;
    elevators[i].is_door_open = 0;
  }

  // Simulate elevator movement
  while (1) {
    for (int i = 0; i < MAX_ELEVATORS; i++) {
      move_elevator(&elevators[i]);
    }

    // Print elevator status
    for (int i = 0; i < MAX_ELEVATORS; i++) {
      print_elevator_status(&elevators[i]);
    }

    // Handle user input
    char command;
    scanf("%c", &command);
    switch (command) {
      case 'O':
        for (int i = 0; i < MAX_ELEVATORS; i++) {
          open_door(&elevators[i]);
        }
        break;
      case 'C':
        for (int i = 0; i < MAX_ELEVATORS; i++) {
          close_door(&elevators[i]);
        }
        break;
      default:
        break;
    }
  }

  return 0;
}