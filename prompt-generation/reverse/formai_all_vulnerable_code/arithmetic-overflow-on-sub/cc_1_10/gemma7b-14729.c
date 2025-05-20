//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct car {
  int x, y, direction, speed;
  char model[20];
} car;

car cars[MAX_CARS];

void initialize_cars() {
  for (int i = 0; i < MAX_CARS; i++) {
    cars[i].x = rand() % 1000;
    cars[i].y = rand() % 1000;
    cars[i].direction = rand() % 4;
    cars[i].speed = rand() % 5;
    strcpy(cars[i].model, "Rusty Ford");
  }
}

void simulate_traffic() {
  time_t t = time(NULL);
  for (int i = 0; i < MAX_CARS; i++) {
    switch (cars[i].direction) {
      case 0:
        cars[i].x++;
        break;
      case 1:
        cars[i].x--;
        break;
      case 2:
        cars[i].y++;
        break;
      case 3:
        cars[i].y--;
        break;
    }

    cars[i].speed++;
    if (cars[i].speed > 10) {
      cars[i].speed = 10;
    }

    if (time(NULL) - t >= 1) {
      t = time(NULL);
      printf("%s is driving at (%d, %d) with speed %d\n", cars[i].model, cars[i].x, cars[i].y, cars[i].speed);
    }
  }
}

int main() {
  initialize_cars();
  simulate_traffic();

  return 0;
}