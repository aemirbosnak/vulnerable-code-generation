//FormAI DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

int main() {

  int speed = 0;
  char direction = 'F';

  printf("Enter a command (F, B, L, R, S): ");
  scanf("%c", &direction);

  switch (direction) {
    case 'F':
      printf("Moving forward.\n");
      break;
    case 'B':
      printf("Moving backward.\n");
      break;
    case 'L':
      printf("Turning left.\n");
      break;
    case 'R':
      printf("Turning right.\n");
      break;
    case 'S':
      printf("Stopping.\n");
      break;
    default:
      printf("Invalid command.\n");
      break;
  }

  if (direction == 'F' || direction == 'B') {
    printf("Enter a speed (0-100): ");
    scanf("%d", &speed);

    if (speed > MAX_SPEED) {
      printf("Speed set to maximum.\n");
      speed = MAX_SPEED;
    } else if (speed < MIN_SPEED) {
      printf("Speed set to minimum.\n");
      speed = MIN_SPEED;
    }

    printf("Moving at %d speed.\n", speed);
  }

  return 0;
}