//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 5
#define MAX_ROAD 10

typedef struct Car {
  int x, y, dir, speed;
} Car;

Car cars[MAX_CARS];
int road[MAX_ROAD][MAX_ROAD];

void initialize() {
  for (int i = 0; i < MAX_CARS; i++) {
    cars[i].x = rand() % MAX_ROAD;
    cars[i].y = rand() % MAX_ROAD;
    cars[i].dir = rand() % 4;
    cars[i].speed = 1 + rand() % 3;
  }

  for (int i = 0; i < MAX_ROAD; i++) {
    for (int j = 0; j < MAX_ROAD; j++) {
      road[i][j] = 0;
    }
  }

  for (int i = 0; i < MAX_CARS; i++) {
    road[cars[i].x][cars[i].y] = 1;
  }
}

void simulate() {
  time_t t = time(NULL);

  for (int i = 0; i < MAX_CARS; i++) {
    switch (cars[i].dir) {
      case 0:
        cars[i].x++;
        break;
      case 1:
        cars[i].y++;
        break;
      case 2:
        cars[i].x--;
        break;
      case 3:
        cars[i].y--;
        break;
    }

    if (road[cars[i].x][cars[i].y] == 1) {
      cars[i].speed = 0;
    }

    if (time(NULL) - t >= cars[i].speed) {
      t = time(NULL);
    }
  }

  for (int i = 0; i < MAX_CARS; i++) {
    road[cars[i].x][cars[i].y] = 0;
    road[cars[i].x][cars[i].y] = 1;
  }
}

int main() {
  initialize();
  simulate();

  return 0;
}