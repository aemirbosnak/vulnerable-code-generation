//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_ROTATION 90

typedef struct Car {
  int x, y, direction, speed;
} Car;

Car car;

void move_car(int direction, int speed) {
  switch (direction) {
    case 0:
      car.x++;
      break;
    case 1:
      car.y++;
      break;
    case 2:
      car.x--;
      break;
    case 3:
      car.y--;
      break;
  }

  car.speed = speed;
}

void turn_car(int rotation) {
  car.direction += rotation;
  if (car.direction > MAX_ROTATION) {
    car.direction = MAX_ROTATION;
  } else if (car.direction < 0) {
    car.direction = 0;
  }
}

int main() {
  car.x = 0;
  car.y = 0;
  car.direction = 0;
  car.speed = 0;

  time_t t = time(NULL);

  while (time(NULL) - t < 10) {
    move_car(1, MAX_SPEED);
    turn_car(20);

    sleep(1);
  }

  return 0;
}