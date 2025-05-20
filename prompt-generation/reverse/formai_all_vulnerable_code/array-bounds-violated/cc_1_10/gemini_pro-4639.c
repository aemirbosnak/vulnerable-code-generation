//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the robot's movements
#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4

// Define the robot's environment
#define ENVIRONMENT_SIZE 10

// Define the robot's sensors
#define SENSOR_FRONT 1
#define SENSOR_LEFT 2
#define SENSOR_RIGHT 3

// Declare the robot's variables
int x, y, orientation;
int sensors[3];

// Initialize the robot's variables
void init_robot() {
  x = 0;
  y = 0;
  orientation = 0;
  for (int i = 0; i < 3; i++) {
    sensors[i] = 0;
  }
}

// Update the robot's sensors
void update_sensors() {
  // Update the front sensor
  if (x + 1 < ENVIRONMENT_SIZE) {
    sensors[SENSOR_FRONT] = 1;
  } else {
    sensors[SENSOR_FRONT] = 0;
  }

  // Update the left sensor
  if (y - 1 >= 0) {
    sensors[SENSOR_LEFT] = 1;
  } else {
    sensors[SENSOR_LEFT] = 0;
  }

  // Update the right sensor
  if (y + 1 < ENVIRONMENT_SIZE) {
    sensors[SENSOR_RIGHT] = 1;
  } else {
    sensors[SENSOR_RIGHT] = 0;
  }
}

// Move the robot forward
void move_forward() {
  switch (orientation) {
    case 0:
      y++;
      break;
    case 1:
      x++;
      break;
    case 2:
      y--;
      break;
    case 3:
      x--;
      break;
  }
}

// Move the robot backward
void move_backward() {
  switch (orientation) {
    case 0:
      y--;
      break;
    case 1:
      x--;
      break;
    case 2:
      y++;
      break;
    case 3:
      x++;
      break;
  }
}

// Turn the robot left
void turn_left() {
  orientation--;
  if (orientation < 0) {
    orientation = 3;
  }
}

// Turn the robot right
void turn_right() {
  orientation++;
  if (orientation > 3) {
    orientation = 0;
  }
}

// Print the robot's environment
void print_environment() {
  for (int i = 0; i < ENVIRONMENT_SIZE; i++) {
    for (int j = 0; j < ENVIRONMENT_SIZE; j++) {
      if (i == x && j == y) {
        printf("R");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Initialize the robot
  init_robot();

  // Update the robot's sensors
  update_sensors();

  // Print the robot's environment
  print_environment();

  // Move the robot forward
  move_forward();

  // Update the robot's sensors
  update_sensors();

  // Print the robot's environment
  print_environment();

  return 0;
}