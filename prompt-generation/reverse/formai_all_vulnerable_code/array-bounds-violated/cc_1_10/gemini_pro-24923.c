//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the robot's movement commands
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Define the robot's sensor readings
#define OBSTACLE 1
#define CLEAR 0

// Define the robot's environment
#define SIZE 10

// Create the robot's environment
int environment[SIZE][SIZE];

// Create the robot's position and orientation
int x, y, orientation;

// Initialize the robot's environment
void init_environment() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      environment[i][j] = CLEAR;
    }
  }
}

// Initialize the robot's position and orientation
void init_robot() {
  x = SIZE / 2;
  y = SIZE / 2;
  orientation = FORWARD;
}

// Get the robot's sensor reading
int get_sensor_reading() {
  switch (orientation) {
    case FORWARD:
      return environment[x][y + 1];
    case BACKWARD:
      return environment[x][y - 1];
    case LEFT:
      return environment[x - 1][y];
    case RIGHT:
      return environment[x + 1][y];
  }
}

// Move the robot forward
void move_forward() {
  switch (orientation) {
    case FORWARD:
      y++;
      break;
    case BACKWARD:
      y--;
      break;
    case LEFT:
      x++;
      break;
    case RIGHT:
      x--;
      break;
  }
}

// Turn the robot left
void turn_left() {
  orientation = (orientation + 1) % 4;
}

// Turn the robot right
void turn_right() {
  orientation = (orientation + 3) % 4;
}

// Control the robot's movement
void control_robot() {
  int sensor_reading = get_sensor_reading();

  if (sensor_reading == OBSTACLE) {
    turn_left();
  } else {
    move_forward();
  }
}

// Print the robot's environment
void print_environment() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (x == j && y == i) {
        printf("R");
      } else if (environment[i][j] == OBSTACLE) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  // Initialize the robot's environment
  init_environment();

  // Initialize the robot's position and orientation
  init_robot();

  // Control the robot's movement
  while (1) {
    control_robot();

    // Print the robot's environment
    print_environment();
  }

  return 0;
}