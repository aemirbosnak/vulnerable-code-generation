//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Robot movement commands
#define FORWARD "FORWARD"
#define BACKWARD "BACKWARD"
#define LEFT "LEFT"
#define RIGHT "RIGHT"
#define STOP "STOP"

// Maximum command length
#define MAX_COMMAND_LENGTH 10

// Robot movement function
void move_robot(char *command) {
  // Check if the command is valid
  if (strcmp(command, FORWARD) != 0 && strcmp(command, BACKWARD) != 0 && strcmp(command, LEFT) != 0 && strcmp(command, RIGHT) != 0 && strcmp(command, STOP) != 0) {
    printf("Invalid command: %s\n", command);
    return;
  }

  // Execute the command
  if (strcmp(command, FORWARD) == 0) {
    printf("Moving forward\n");
  } else if (strcmp(command, BACKWARD) == 0) {
    printf("Moving backward\n");
  } else if (strcmp(command, LEFT) == 0) {
    printf("Turning left\n");
  } else if (strcmp(command, RIGHT) == 0) {
    printf("Turning right\n");
  } else if (strcmp(command, STOP) == 0) {
    printf("Stopping\n");
  }
}

// Main function
int main() {
  // Get the robot's initial position
  int x = 0;
  int y = 0;

  // Get the robot's initial orientation
  char orientation = 'N';

  // Get the robot's movement commands
  char commands[100];
  scanf("%s", commands);

  // Execute the robot's movement commands
  char *command = strtok(commands, ",");
  while (command != NULL) {
    move_robot(command);

    // Update the robot's position and orientation
    if (strcmp(command, FORWARD) == 0) {
      if (orientation == 'N') {
        y++;
      } else if (orientation == 'S') {
        y--;
      } else if (orientation == 'E') {
        x++;
      } else if (orientation == 'W') {
        x--;
      }
    } else if (strcmp(command, BACKWARD) == 0) {
      if (orientation == 'N') {
        y--;
      } else if (orientation == 'S') {
        y++;
      } else if (orientation == 'E') {
        x--;
      } else if (orientation == 'W') {
        x++;
      }
    } else if (strcmp(command, LEFT) == 0) {
      if (orientation == 'N') {
        orientation = 'W';
      } else if (orientation == 'S') {
        orientation = 'E';
      } else if (orientation == 'E') {
        orientation = 'N';
      } else if (orientation == 'W') {
        orientation = 'S';
      }
    } else if (strcmp(command, RIGHT) == 0) {
      if (orientation == 'N') {
        orientation = 'E';
      } else if (orientation == 'S') {
        orientation = 'W';
      } else if (orientation == 'E') {
        orientation = 'S';
      } else if (orientation == 'W') {
        orientation = 'N';
      }
    }

    // Get the next movement command
    command = strtok(NULL, ",");
  }

  // Print the robot's final position and orientation
  printf("Final position: (%d, %d)\n", x, y);
  printf("Final orientation: %c\n", orientation);

  return 0;
}