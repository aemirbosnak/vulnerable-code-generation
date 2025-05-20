//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of steps and commands for the simulation
#define MAX_STEPS 100
#define MAX_COMMANDS 10

// Define the struct for the remote control vehicle
typedef struct {
  int x; // X coordinate
  int y; // Y coordinate
  int direction; // 0: North, 1: East, 2: South, 3: West
} rc_vehicle;

// Function for moving the vehicle forward
void move_forward(rc_vehicle *vehicle) {
  if (vehicle->direction == 0) // Moving north
    vehicle->y++;
  else if (vehicle->direction == 1) // Moving east
    vehicle->x++;
  else if (vehicle->direction == 2) // Moving south
    vehicle->y--;
  else if (vehicle->direction == 3) // Moving west
    vehicle->x--;
}

// Function for turning the vehicle left
void turn_left(rc_vehicle *vehicle) {
  vehicle->direction--;
  if (vehicle->direction < 0)
    vehicle->direction = 3;
}

// Function for turning the vehicle right
void turn_right(rc_vehicle *vehicle) {
  vehicle->direction++;
  if (vehicle->direction > 3)
    vehicle->direction = 0;
}

int main(void) {
  rc_vehicle vehicle = {0, 0, 0};
  char commands[MAX_COMMANDS];
  int steps[MAX_STEPS];
  int num_steps = 0;
  int i, j;

  // Get the commands from the user
  printf("Enter commands (F: move forward, L: turn left, R: turn right)\n");
  scanf("%s", commands);

  // Parse the commands and fill in the steps array
  for (i = 0; commands[i]; i++) {
    if (commands[i] == 'F') {
      steps[num_steps] = 0;
      num_steps++;
    } else if (commands[i] == 'L') {
      steps[num_steps] = 1;
      num_steps++;
    } else if (commands[i] == 'R') {
      steps[num_steps] = 2;
      num_steps++;
    }
  }

  // Run the simulation
  for (i = 0; i < num_steps; i++) {
    if (steps[i] == 0) { // Move forward
      move_forward(&vehicle);
    } else if (steps[i] == 1) { // Turn left
      turn_left(&vehicle);
    } else if (steps[i] == 2) { // Turn right
      turn_right(&vehicle);
    }

    // Print the current state of the vehicle
    printf("Step %d: X=%d, Y=%d, Direction=%d\n", i+1, vehicle.x, vehicle.y, vehicle.direction);
  }

  return 0;
}