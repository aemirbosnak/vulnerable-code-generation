//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STEPS 100

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  Position position;
  int direction; // 0: north, 1: east, 2: south, 3: west
} Robot;

void move_forward(Robot *robot) {
  switch (robot->direction) {
    case 0:
      robot->position.y++;
      break;
    case 1:
      robot->position.x++;
      break;
    case 2:
      robot->position.y--;
      break;
    case 3:
      robot->position.x--;
      break;
  }
}

void turn_left(Robot *robot) {
  robot->direction = (robot->direction + 1) % 4;
}

void turn_right(Robot *robot) {
  robot->direction = (robot->direction + 3) % 4;
}

int main() {
  Robot robot;
  char *steps = malloc(MAX_STEPS + 1);

  printf("Enter a sequence of steps (F: forward, L: left, R: right): ");
  scanf("%s", steps);

  for (int i = 0; i < strlen(steps); i++) {
    switch (steps[i]) {
      case 'F':
        move_forward(&robot);
        break;
      case 'L':
        turn_left(&robot);
        break;
      case 'R':
        turn_right(&robot);
        break;
    }
  }

  printf("The robot's final position is (%d, %d)\n", robot.position.x, robot.position.y);

  free(steps);
  return 0;
}