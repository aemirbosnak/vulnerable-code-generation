//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 10 // number of floors in the building
#define NUM_ELEVATORS 3 // number of elevators in the building
#define MAX_CAPACITY 10 // maximum capacity of each elevator

// Function to simulate the movement of an elevator
void move_elevator(int *currentFloor, int destinationFloor, char *direction) {
  if (*currentFloor < destinationFloor) {
    *currentFloor += 1;
    *direction = 'u';
    printf("Elevator going up to floor %d\n", *currentFloor);
  } else if (*currentFloor > destinationFloor) {
    *currentFloor -= 1;
    *direction = 'd';
    printf("Elevator going down to floor %d\n", *currentFloor);
  } else {
    *direction = 's';
    printf("Elevator has arrived at floor %d\n", *currentFloor);
  }
}

int main() {
  // Initialize elevator variables
  int elevator1[NUM_ELEVATORS], elevator2[NUM_ELEVATORS], elevator3[NUM_ELEVATORS];
  int elevator1_currentFloor = 1, elevator2_currentFloor = 1, elevator3_currentFloor = 1;
  char elevator1_direction = 's', elevator2_direction = 's', elevator3_direction = 's';
  bool elevator1_moving = false, elevator2_moving = false, elevator3_moving = false;

  // Initialize destination variables
  int dest1 = -1, dest2 = -1, dest3 = -1;

  // Initialize floor variables
  int floor_request = -1;
  bool floor_requested[NUM_FLOORS] = {false};

  while (true) {
    // Prompt for floor requests
    printf("Enter floor number to go to (1-%d) or 0 to exit: ", NUM_FLOORS);
    scanf("%d", &floor_request);
    if (floor_request == 0) {
      break; // Exit the simulation
    }
    if (floor_request < 1 || floor_request > NUM_FLOORS) {
      printf("Invalid floor number. Please enter a number between 1 and %d.\n", NUM_FLOORS);
      continue;
    }

    // Floor request is valid
    floor_requested[floor_request - 1] = true;
    printf("Floor %d requested.\n", floor_request);

    // Check if any elevators are available
    if (elevator1_moving == false) {
      elevator1_moving = true;
      dest1 = floor_request;
    } else if (elevator2_moving == false) {
      elevator2_moving = true;
      dest2 = floor_request;
    } else if (elevator3_moving == false) {
      elevator3_moving = true;
      dest3 = floor_request;
    } else {
      // All elevators are busy, so find the closest elevator and assign the request
      int elevator1_distance = abs(elevator1_currentFloor - floor_request);
      int elevator2_distance = abs(elevator2_currentFloor - floor_request);
      int elevator3_distance = abs(elevator3_currentFloor - floor_request);
      if (elevator1_direction == 'u' && floor_request >= elevator1_currentFloor) {
        elevator1_distance -= 1;
      }
      if (elevator1_direction == 'd' && floor_request <= elevator1_currentFloor) {
        elevator1_distance -= 1;
      }
      if (elevator2_direction == 'u' && floor_request >= elevator2_currentFloor) {
        elevator2_distance -= 1;
      }
      if (elevator2_direction == 'd' && floor_request <= elevator2_currentFloor) {
        elevator2_distance -= 1;
      }
      if (elevator3_direction == 'u' && floor_request >= elevator3_currentFloor) {
        elevator3_distance -= 1;
      }
      if (elevator3_direction == 'd' && floor_request <= elevator3_currentFloor) {
        elevator3_distance -= 1;
      }
      int min_distance = elevator1_distance;
      int min_elevator = 1;
      if (elevator2_distance < min_distance) {
        min_distance = elevator2_distance;
        min_elevator = 2;
      }
      if (elevator3_distance < min_distance) {
        min_distance = elevator3_distance;
        min_elevator = 3;
      }

      // Assign the floor request to the closest available elevator
      if (min_elevator == 1) {
        elevator1_moving = true;
        dest1 = floor_request;
      } else if (min_elevator == 2) {
        elevator2_moving = true;
        dest2 = floor_request;
      } else {
        elevator3_moving = true;
        dest3 = floor_request;
      }
    }

    // Loop through all elevators and move them to their destinations
    for (int i = 0; i < NUM_ELEVATORS; i++) {
      if (elevator1_moving && elevator1[i] != -1) {
        move_elevator(&elevator1_currentFloor, elevator1[i], &elevator1_direction);
        if (elevator1_currentFloor == dest1) {
          printf("Elevator 1 has arrived at floor %d\n", dest1);
          elevator1_moving = false;
          elevator1_direction = 's';
          elevator1[i] = -1;
        }
      }
      if (elevator2_moving && elevator2[i] != -1) {
        move_elevator(&elevator2_currentFloor, elevator2[i], &elevator2_direction);
        if (elevator2_currentFloor == dest2) {
          printf("Elevator 2 has arrived at floor %d\n", dest2);
          elevator2_moving = false;
          elevator2_direction = 's';
          elevator2[i] = -1;
        }
      }
      if (elevator3_moving && elevator3[i] != -1) {
        move_elevator(&elevator3_currentFloor, elevator3[i], &elevator3_direction);
        if (elevator3_currentFloor == dest3) {
          printf("Elevator 3 has arrived at floor %d\n", dest3);
          elevator3_moving = false;
          elevator3_direction = 's';
          elevator3[i] = -1;
        }
      }
    }

    // Loop through all floors and assign requests to the elevators
    for (int i = 0; i < NUM_FLOORS; i++) {
      if (floor_requested[i]) {
        int elevator_distance[NUM_ELEVATORS];
        for (int j = 0; j < NUM_ELEVATORS; j++) {
          if ((j == 0 && elevator1_moving == false) || (j == 1 && elevator2_moving == false) || (j == 2 && elevator3_moving == false)) {
            elevator_distance[j] = abs(i + 1 - (j == 0 ? elevator1_currentFloor : (j == 1 ? elevator2_currentFloor : elevator3_currentFloor)));
            if ((j == 0 && elevator1_direction == 'u' && i + 1 > elevator1_currentFloor) || (j == 1 && elevator2_direction == 'u' && i + 1 > elevator2_currentFloor) || (j == 2 && elevator3_direction == 'u' && i + 1 > elevator3_currentFloor)) {
              elevator_distance[j] -= 1;
            }
            if ((j == 0 && elevator1_direction == 'd' && i + 1 < elevator1_currentFloor) || (j == 1 && elevator2_direction == 'd' && i + 1 < elevator2_currentFloor) || (j == 2 && elevator3_direction == 'd' && i + 1 < elevator3_currentFloor)) {
              elevator_distance[j] -= 1;
            }
          } else {
            elevator_distance[j] = MAX_CAPACITY;
          }
        }
        int min_elevator = 0;
        for (int j = 1; j < NUM_ELEVATORS; j++) {
          if (elevator_distance[j] < elevator_distance[min_elevator]) {
            min_elevator = j;
          }
        }
        if ((min_elevator == 0 && elevator1_moving == false) || (min_elevator == 1 && elevator2_moving == false) || (min_elevator == 2 && elevator3_moving == false)) {
          if (min_elevator == 0) {
            for (int j = 0; j < MAX_CAPACITY; j++) {
              if (elevator1[j] == -1) {
                elevator1[j] = i + 1;
                break;
              }
            }
          } else if (min_elevator == 1) {
            for (int j = 0; j < MAX_CAPACITY; j++) {
              if (elevator2[j] == -1) {
                elevator2[j] = i + 1;
                break;
              }
            }
          } else {
            for (int j = 0; j < MAX_CAPACITY; j++) {
              if (elevator3[j] == -1) {
                elevator3[j] = i + 1;
                break;
              }
            }
          }
          printf("Floor %d assigned to elevator %d\n", i + 1, min_elevator + 1);
          floor_requested[i] = false;
        }
      }
    }
  }
  printf("Exiting the elevator simulation!\n");
  return 0;
}