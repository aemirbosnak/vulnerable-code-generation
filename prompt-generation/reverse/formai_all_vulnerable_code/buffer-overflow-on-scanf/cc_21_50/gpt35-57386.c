//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: active
#include <stdio.h>

int main() {
  int speed = 0;
  char direction = 'N';

  printf("Welcome to the Remote Control Vehicle Simulation Program!\n");
  printf("Enter a speed between 0 and 100: ");
  scanf("%d", &speed);

  if (speed < 0 || speed > 100) {
    printf("Invalid speed entered. Exiting program.\n");
    return 0;
  }

  printf("Enter a direction North(N), South(S), East(E), or West(W): ");
  scanf(" %c", &direction);

  if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W') {
    printf("Invalid direction entered. Exiting program.\n");
    return 0;
  }

  printf("Starting Remote Control Vehicle simulation...\n");
  printf("Speed: %d, Direction: %c\n", speed, direction);

  // Simulation loop
  while (1) {
    printf("Vehicle is currently moving at a speed of %d in a %c direction.\n", speed, direction);

    char command;
    printf("Enter a command (a: accelerate, d: decelerate, t: turn left, r: turn right, s: stop): ");
    scanf(" %c", &command);

    if (command == 'a') {
      speed += 10;
      if (speed > 100) speed = 100;
      printf("Vehicle has accelerated to a speed of %d.\n", speed);
    } else if (command == 'd') {
      speed -= 10;
      if (speed < 0) speed = 0;
      printf("Vehicle has decelerated to a speed of %d.\n", speed);
    } else if (command == 't') {
      switch (direction) {
        case 'N':
          direction = 'W';
          break;
        case 'S':
          direction = 'E';
          break;
        case 'E':
          direction = 'N';
          break;
        case 'W':
          direction = 'S';
          break;
      }
      printf("Vehicle has turned left, now facing %c.\n", direction);
    } else if (command == 'r') {
      switch (direction) {
        case 'N':
          direction = 'E';
          break;
        case 'S':
          direction = 'W';
          break;
        case 'E':
          direction = 'S';
          break;
        case 'W':
          direction = 'N';
          break;
      }
      printf("Vehicle has turned right, now facing %c.\n", direction);
    } else if (command == 's') {
      printf("Vehicle has come to a stop.\n");
      break;
    } else {
      printf("Invalid command entered. Please try again.\n");
    }
  }

  printf("Exiting Remote Control Vehicle simulation. Thank you for using our program!\n");

  return 0;
}