//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Touring
#include <stdio.h>

int main() {
  int x = 0, y = 0; // starting position of vehicle
  char dir = 'N'; // starting direction of vehicle
  char input;

  printf("Welcome to the Remote Control Vehicle Simulation!\n");
  printf("Use WASD to move the vehicle and Q to quit.\n");

  while (input != 'Q') {
    printf("Current position: (%d, %d)\n", x, y);
    printf("Current direction: %c\n", dir);
    printf("Enter a command: ");

    scanf(" %c", &input); // take input from user

    switch (input) { // perform action based on input
      case 'W':
        if (dir == 'N') {
          y++;
        } else if (dir == 'S') {
          y--;
        } else if (dir == 'E') {
          x++;
        } else if (dir == 'W') {
          x--;
        }
        break;
      case 'A':
        if (dir == 'N') {
          dir = 'W';
        } else if (dir == 'S') {
          dir = 'E';
        } else if (dir == 'E') {
          dir = 'N';
        } else if (dir == 'W') {
          dir = 'S';
        }
        break;
      case 'S':
        if (dir == 'N') {
          y--;
        } else if (dir == 'S') {
          y++;
        } else if (dir == 'E') {
          x--;
        } else if (dir == 'W') {
          x++;
        }
        break;
      case 'D':
        if (dir == 'N') {
          dir = 'E';
        } else if (dir == 'S') {
          dir = 'W';
        } else if (dir == 'E') {
          dir = 'S';
        } else if (dir == 'W') {
          dir = 'N';
        }
        break;
      case 'Q':
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid input.\n");
        break;
    }
  }

  return 0;
}