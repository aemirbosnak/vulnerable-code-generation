#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char command;
  int speed, direction;

  // Validate input format
  if (scanf(" %c %d %d ", &command, &speed, &direction) != 3) {
    return 1;
  }

  // Check for valid command
  switch (command) {
    case 'f':
      // Forward motion
      if (speed > 0) {
        // Code to execute forward motion
      } else {
        printf("Error: Invalid speed or direction.\n");
      }
      break;
    case 'b':
      // Backward motion
      if (speed > 0) {
        // Code to execute backward motion
      } else {
        printf("Error: Invalid speed or direction.\n");
      }
      break;
    case 'l':
      // Left turn
      if (direction > 0) {
        // Code to execute left turn
      } else {
        printf("Error: Invalid speed or direction.\n");
      }
      break;
    case 'r':
      // Right turn
      if (direction > 0) {
        // Code to execute right turn
      } else {
        printf("Error: Invalid speed or direction.\n");
      }
      break;
    default:
      printf("Error: Invalid command.\n");
  }

  return 0;
}
