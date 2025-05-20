//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

/* This program simulates a remote control car using C programming language */

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_STEER_ANGLE 45
#define MIN_STEER_ANGLE -45

int main() {

  int speed = 0; // initial speed
  int steerAngle = 0; // initial steering angle

  while (1) {
    char action;

    printf("\nCurrent Speed: %d\nCurrent Steering Angle: %d\n", speed, steerAngle);

    printf("Enter Action (s - speed up, b - brake, l - turn left, r - turn right, q - quit): ");

    scanf(" %c", &action);

    switch (action) {
      case 's':
        if (speed < MAX_SPEED) {
          speed += 10;
        }
        break;
      case 'b':
        if (speed > MIN_SPEED) {
          speed -= 10;
        }
        break;
      case 'l':
        if (steerAngle > MIN_STEER_ANGLE) {
          steerAngle -= 5;
        }
        break;
      case 'r':
        if (steerAngle < MAX_STEER_ANGLE) {
          steerAngle += 5;
        }
        break;
      case 'q':
        exit(0);
      default:
        printf("Invalid Action!\n");
        break;
    }
  }

  return 0;
}