//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the robot's movement commands
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

// Define the robot's configuration parameters
#define SPEED 10
#define TURN_RADIUS 5

// Define the robot's state variables
int x = 0;
int y = 0;
int theta = 0;

// Function to move the robot forward
void forward() {
  x += SPEED * cos(theta);
  y += SPEED * sin(theta);
}

// Function to move the robot backward
void backward() {
  x -= SPEED * cos(theta);
  y -= SPEED * sin(theta);
}

// Function to turn the robot left
void left() {
  theta -= TURN_RADIUS;
}

// Function to turn the robot right
void right() {
  theta += TURN_RADIUS;
}

// Function to stop the robot
void stop() {
  // Do nothing
}

// Main function
int main() {
  // Get the robot's movement commands from the user
  int command;
  while (1) {
    printf("Enter a movement command (1: forward, 2: backward, 3: left, 4: right, 5: stop): ");
    scanf("%d", &command);

    // Execute the robot's movement command
    switch (command) {
      case FORWARD:
        forward();
        break;
      case BACKWARD:
        backward();
        break;
      case LEFT:
        left();
        break;
      case RIGHT:
        right();
        break;
      case STOP:
        stop();
        break;
      default:
        printf("Invalid command\n");
    }

    // Print the robot's state
    printf("Robot state: x = %d, y = %d, theta = %d\n", x, y, theta);
  }

  return 0;
}