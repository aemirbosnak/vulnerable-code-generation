//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

typedef enum {
  STOP,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
} direction;

typedef struct {
  int x;
  int y;
  direction direction;
} car;

void move_car(car *car, direction direction) {
  switch (direction) {
    case FORWARD:
      car->y++;
      break;
    case BACKWARD:
      car->y--;
      break;
    case LEFT:
      car->x--;
      break;
    case RIGHT:
      car->x++;
      break;
    default:
      break;
  }
}

void print_car(car *car) {
  printf("(%d, %d)\n", car->x, car->y);
}

int main() {
  car car = {0, 0, STOP};
  char *commands[] = {"STOP", "FORWARD", "BACKWARD", "LEFT", "RIGHT"};

  while (1) {
    char command[100];
    scanf("%s", command);

    for (int i = 0; i < ARRAY_SIZE(commands); i++) {
      if (strcmp(command, commands[i]) == 0) {
        move_car(&car, i);
      }
    }

    print_car(&car);
  }

  return 0;
}