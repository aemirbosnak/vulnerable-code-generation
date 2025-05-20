//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define NUM_WHEELS 4

typedef struct Wheel {
  int x, y, dir;
} Wheel;

Wheel wheels[NUM_WHEELS] = {
  {0, 0, 0},
  {0, 0, 1},
  {0, 0, 2},
  {0, 0, 3}
};

void move(int direction) {
  switch (direction) {
    case 0:
      for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].dir = 0;
      }
      break;
    case 1:
      for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].dir = 1;
      }
      break;
    case 2:
      for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].dir = 2;
      }
      break;
    case 3:
      for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].dir = 3;
      }
      break;
  }
}

int main() {
  int direction = 0;

  while (1) {
    printf("Enter direction (0-3): ");
    scanf("%d", &direction);

    move(direction);

    printf("Wheels are moving in direction %d\n", direction);

    for (int i = 0; i < NUM_WHEELS; i++) {
      printf("Wheel %d: x = %d, y = %d, dir = %d\n", i, wheels[i].x, wheels[i].y, wheels[i].dir);
    }

    printf("\n");
  }

  return 0;
}