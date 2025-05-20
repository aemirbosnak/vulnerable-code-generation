//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Robot movement control commands
#define FORWARD  1
#define BACKWARD 2
#define LEFT     3
#define RIGHT    4
#define STOP     5

// Robot movement speeds
#define SLOW    1
#define MEDIUM  2
#define FAST    3

// Robot movement durations
#define SHORT   1
#define MEDIUM  2
#define LONG    3

// Main function
int main() {
  // Variables to store the robot's movement commands and speeds
  int command, speed, duration;

  // Get the robot's movement commands from the user
  printf("Enter a movement command (1=forward, 2=backward, 3=left, 4=right, 5=stop): ");
  scanf("%d", &command);

  // Get the robot's movement speed from the user
  printf("Enter a movement speed (1=slow, 2=medium, 3=fast): ");
  scanf("%d", &speed);

  // Get the robot's movement duration from the user
  printf("Enter a movement duration (1=short, 2=medium, 3=long): ");
  scanf("%d", &duration);

  // Send the robot's movement commands to the robot controller
  switch (command) {
    case FORWARD:
      printf("Sending forward command to robot controller.\n");
      break;
    case BACKWARD:
      printf("Sending backward command to robot controller.\n");
      break;
    case LEFT:
      printf("Sending left command to robot controller.\n");
      break;
    case RIGHT:
      printf("Sending right command to robot controller.\n");
      break;
    case STOP:
      printf("Sending stop command to robot controller.\n");
      break;
  }

  // Set the robot's movement speed
  switch (speed) {
    case SLOW:
      printf("Setting slow speed for robot.\n");
      break;
    case MEDIUM:
      printf("Setting medium speed for robot.\n");
      break;
    case FAST:
      printf("Setting fast speed for robot.\n");
      break;
  }

  // Set the robot's movement duration
  switch (duration) {
    case SHORT:
      printf("Setting short duration for robot movement.\n");
      break;
    case MEDIUM:
      printf("Setting medium duration for robot movement.\n");
      break;
    case LONG:
      printf("Setting long duration for robot movement.\n");
      break;
  }

  // Wait for the robot to complete its movement
  sleep(duration);

  // Stop the robot
  printf("Sending stop command to robot controller.\n");

  return 0;
}