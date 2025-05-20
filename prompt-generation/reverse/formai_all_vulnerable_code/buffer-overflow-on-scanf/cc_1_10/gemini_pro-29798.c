//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  LEFT,
  RIGHT,
  UP,
  DOWN
} direction;

typedef struct {
  int x;
  int y;
  direction dir;
} drone;

void move(drone *d, direction dir) {
  switch (dir) {
  case LEFT:
    d->x--;
    break;
  case RIGHT:
    d->x++;
    break;
  case UP:
    d->y++;
    break;
  case DOWN:
    d->y--;
    break;
  }
}

void print_drone(drone *d) {
  printf("(%d, %d)\n", d->x, d->y);
}

int main() {
  drone d = {0, 0, RIGHT};

  while (1) {
    char command;
    scanf(" %c", &command);

    switch (command) {
    case 'w':
      move(&d, UP);
      break;
    case 's':
      move(&d, DOWN);
      break;
    case 'a':
      move(&d, LEFT);
      break;
    case 'd':
      move(&d, RIGHT);
      break;
    case 'p':
      print_drone(&d);
      break;
    case 'q':
      exit(0);
    }
  }

  return 0;
}