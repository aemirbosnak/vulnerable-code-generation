//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  double x, y; // Coordinates
  double theta; // Heading (radians)
  double v; // Velocity (m/s)
  double w; // Angular velocity (rad/s)
} Robot;

void draw_robot(Robot r) {
  printf("(%f, %f)\n", r.x, r.y);
}

int main() {
  srand(time(NULL));

  // Initialize the robot
  Robot robot = {0, 0, 0, 0, 0};

  // Main loop
  while (1) {
    // Get user input
    char command;
    printf("Enter a command (f/b/l/r/q): ");
    scanf(" %c", &command);

    // Update the robot's state based on the command
    switch (command) {
    case 'f': // Forward
      robot.x += robot.v * cos(robot.theta) * 0.1;
      robot.y += robot.v * sin(robot.theta) * 0.1;
      break;
    case 'b': // Backward
      robot.x -= robot.v * cos(robot.theta) * 0.1;
      robot.y -= robot.v * sin(robot.theta) * 0.1;
      break;
    case 'l': // Left
      robot.theta -= robot.w * 0.1;
      break;
    case 'r': // Right
      robot.theta += robot.w * 0.1;
      break;
    case 'q': // Quit
      exit(0);
      break;
    }

    // Draw the robot
    draw_robot(robot);
  }

  return 0;
}