//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the robot's initial position and orientation
int x = 0, y = 0, orientation = 0;

// Define the robot's movement commands
#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'

// Define the robot's sensor commands
#define GET_X 'x'
#define GET_Y 'y'
#define GET_ORIENTATION 'o'

// Define the robot's debug commands
#define DEBUG_PRINT 'p'

// Define the robot's exit command
#define EXIT 'q'

// Main program loop
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the robot's initial position and orientation from the user
  printf("Enter the robot's initial x position: ");
  scanf("%d", &x);
  printf("Enter the robot's initial y position: ");
  scanf("%d", &y);
  printf("Enter the robot's initial orientation (0 for north, 1 for east, 2 for south, 3 for west): ");
  scanf("%d", &orientation);

  // Main program loop
  while (1) {
    // Get the robot's next command from the user
    char command;
    printf("Enter a command (w/s/a/d/x/y/o/p/q): ");
    scanf(" %c", &command);

    // Execute the robot's command
    switch (command) {
      case FORWARD:
        // Move the robot forward one unit
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
        break;
      case BACKWARD:
        // Move the robot backward one unit
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
        break;
      case LEFT:
        // Turn the robot left 90 degrees
        orientation = (orientation + 3) % 4;
        break;
      case RIGHT:
        // Turn the robot right 90 degrees
        orientation = (orientation + 1) % 4;
        break;
      case GET_X:
        // Get the robot's x position
        printf("The robot's x position is %d\n", x);
        break;
      case GET_Y:
        // Get the robot's y position
        printf("The robot's y position is %d\n", y);
        break;
      case GET_ORIENTATION:
        // Get the robot's orientation
        printf("The robot's orientation is %d\n", orientation);
        break;
      case DEBUG_PRINT:
        // Print the robot's current state
        printf("The robot is at (%d, %d) and facing %d\n", x, y, orientation);
        break;
      case EXIT:
        // Exit the program
        return 0;
    }
  }

  return 0;
}