//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>

// Define the length and width of the simulated area
#define LENGTH 10
#define WIDTH 10

int main() {
  // Define the start position of the remote control vehicle
  int x_pos = 0;
  int y_pos = 0;

  char command;
  printf("Welcome to the Remote Control Vehicle Simulation.\n");

  // Keep getting commands from the user until they exit with 'q'
  while (1) {
    printf("Enter a command (u: up, d: down, l: left, r: right, q: quit): ");
    scanf(" %c", &command);

    // Check if the user wants to quit
    if (command == 'q') {
      printf("Exiting remote control vehicle simulation.\n");
      break;
    }

    // Move the remote control vehicle based on the command
    switch (command) {
      case 'u':
        if (y_pos > 0) {
          y_pos--;
        }
        break;
      case 'd':
        if (y_pos < LENGTH - 1) {
          y_pos++;
        }
        break;
      case 'l':
        if (x_pos > 0) {
          x_pos--;
        }
        break;
      case 'r':
        if (x_pos < WIDTH - 1) {
          x_pos++;
        }
        break;
      default:
        printf("Invalid command. Please try again.\n");
        break;
    }

    // Print out the current position of the remote control vehicle
    printf("Remote control vehicle position: (%d, %d)\n", x_pos, y_pos);
  }

  return 0;
}