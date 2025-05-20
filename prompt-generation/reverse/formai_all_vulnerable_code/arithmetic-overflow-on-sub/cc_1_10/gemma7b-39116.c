//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

struct car {
  int x;
  int y;
  int direction;
  int speed;
};

void move_car(struct car *car) {
  switch (car->direction) {
    case 0:
      car->x++;
      break;
    case 1:
      car->y++;
      break;
    case 2:
      car->x--;
      break;
    case 3:
      car->y--;
      break;
  }

  car->speed++;
  if (car->speed > 5) {
    car->speed = 5;
  }
}

int main() {
  struct car cars[MAX_CARS];
  for (int i = 0; i < MAX_CARS; i++) {
    cars[i].x = rand() % 10;
    cars[i].y = rand() % 10;
    cars[i].direction = rand() % 4;
    cars[i].speed = rand() % 5;
  }

  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 60) {
    for (int i = 0; i < MAX_CARS; i++) {
      move_car(&cars[i]);
    }

    system("clear");
    for (int i = 0; i < MAX_CARS; i++) {
      printf("Car %d: (%d, %d) Direction: %d Speed: %d\n", i + 1, cars[i].x, cars[i].y, cars[i].direction, cars[i].speed);
    }

    sleep(1);
  }

  return 0;
}