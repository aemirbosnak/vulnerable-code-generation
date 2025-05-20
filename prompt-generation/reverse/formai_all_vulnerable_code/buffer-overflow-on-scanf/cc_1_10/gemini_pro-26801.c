//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the robot's parameters
#define ROBOT_LENGTH 10.0 // in cm
#define ROBOT_WIDTH 5.0 // in cm
#define ROBOT_WEIGHT 10.0 // in kg

// Define the environment's parameters
#define ENVIRONMENT_LENGTH 100.0 // in cm
#define ENVIRONMENT_WIDTH 50.0 // in cm

// Define the robot's movement commands
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 0

// Define the robot's initial position and orientation
double robot_x = 0.0; // in cm
double robot_y = 0.0; // in cm
double robot_theta = 0.0; // in degrees

// Define the environment's obstacles
#define NUM_OBSTACLES 5
double obstacles[NUM_OBSTACLES][2] = {
  {20.0, 20.0}, // in cm
  {40.0, 40.0}, // in cm
  {60.0, 60.0}, // in cm
  {80.0, 80.0}, // in cm
  {100.0, 100.0} // in cm
};

// Main function
int main() {
  // Initialize the robot
  robot_x = 0.0;
  robot_y = 0.0;
  robot_theta = 0.0;

  // Main loop
  while (1) {
    // Get the user's input
    int command;
    printf("Enter a movement command (1: forward, 2: backward, 3: left, 4: right, 0: stop): ");
    scanf("%d", &command);

    // Execute the user's command
    switch (command) {
      case FORWARD:
        robot_x += ROBOT_LENGTH * cos(robot_theta * M_PI / 180.0);
        robot_y += ROBOT_LENGTH * sin(robot_theta * M_PI / 180.0);
        break;
      case BACKWARD:
        robot_x -= ROBOT_LENGTH * cos(robot_theta * M_PI / 180.0);
        robot_y -= ROBOT_LENGTH * sin(robot_theta * M_PI / 180.0);
        break;
      case LEFT:
        robot_theta -= 90.0;
        break;
      case RIGHT:
        robot_theta += 90.0;
        break;
      case STOP:
        break;
      default:
        printf("Invalid command.\n");
        break;
    }

    // Check for collisions
    for (int i = 0; i < NUM_OBSTACLES; i++) {
      if (fabs(robot_x - obstacles[i][0]) < ROBOT_LENGTH / 2.0 &&
          fabs(robot_y - obstacles[i][1]) < ROBOT_WIDTH / 2.0) {
        printf("Collision detected.\n");
        break;
      }
    }

    // Print the robot's position and orientation
    printf("Robot position: (%f, %f)\n", robot_x, robot_y);
    printf("Robot orientation: %f degrees\n", robot_theta);
  }

  return 0;
}