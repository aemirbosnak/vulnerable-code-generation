//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

typedef struct Vehicle {
  char name[20];
  int x, y, facing, speed;
} Vehicle;

Vehicle vehicles[10];

void move_vehicle(Vehicle* v) {
  switch (v->facing) {
    case 0:
      v->x++;
      break;
    case 1:
      v->y++;
      break;
    case 2:
      v->x--;
      break;
    case 3:
      v->y--;
      break;
  }

  v->speed++;
  if (v->speed > MAX_SPEED) {
    v->speed = MAX_SPEED;
  }
}

int main() {
  time_t t = time(NULL);
  srand(t);

  for (int i = 0; i < 10; i++) {
    vehicles[i].name[0] = 'A' + i;
    vehicles[i].x = rand() % 100;
    vehicles[i].y = rand() % 100;
    vehicles[i].facing = rand() % 4;
    vehicles[i].speed = 0;
  }

  while (1) {
    for (int i = 0; i < 10; i++) {
      move_vehicle(&vehicles[i]);
    }

    printf("Time: %ld\n", time(NULL) - t);
    t = time(NULL);

    for (int i = 0; i < 10; i++) {
      printf("%s: (%d, %d) Speed: %d\n", vehicles[i].name, vehicles[i].x, vehicles[i].y, vehicles[i].speed);
    }

    printf("\n");
  }
}