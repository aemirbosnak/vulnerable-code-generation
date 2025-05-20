//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Constants
#define NUM_FLOORS 5
#define ELEVATOR_SIZE 2

// Global variables
int current_floor = 0;
int direction = 1; // 1 for up, -1 for down
int requests[NUM_FLOORS];

void print_state() {
  printf("Elevator is currently on floor %d\n", current_floor);
}

void handle_request(int floor) {
  if (requests[floor] && (current_floor != floor)) {
    printf("Request from floor %d received. Elevator will go to floor %d.\n", floor, floor);
    current_floor = floor;
  }
}

void move_elevator() {
  current_floor += direction;
  printf("Elevator moved %d floors.\n", direction);
  if (requests[current_floor]) {
    printf("Elevator stopped at floor %d to pick up passengers.\n", current_floor);
  }
}

void check_requests() {
  for (int floor = 0; floor < NUM_FLOORS; floor++) {
    if (requests[floor]) {
      handle_request(floor);
      break;
    }
  }
}

int main() {
  for (int i = 0; i < NUM_FLOORS; i++) {
    requests[i] = rand() % 2; // Generate random requests
  }

  printf("Simulation started.\n");

  while (1) {
    print_state();
    check_requests();
    move_elevator();
  }

  return 0;
}