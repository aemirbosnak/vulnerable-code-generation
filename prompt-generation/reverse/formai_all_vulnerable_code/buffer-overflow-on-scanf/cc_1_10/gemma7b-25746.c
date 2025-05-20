//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_TURN 30

typedef struct RC_Car {
  int x, y, direction, speed, timer;
} RC_Car;

RC_Car car;

void update_car_position() {
  switch (car.direction) {
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
}

void handle_remote_input() {
  int input;

  printf("Enter input (0-3): ");
  scanf("%d", &input);

  switch (input) {
    case 0:
      car.speed = 0;
      break;
    case 1:
      car.speed = MAX_SPEED;
      break;
    case 2:
      car.direction = (car.direction + 1) % MAX_TURN;
      break;
    case 3:
      car.direction = (car.direction - 1) % MAX_TURN;
      break;
  }
}

int main() {
  car.x = 0;
  car.y = 0;
  car.direction = 0;
  car.speed = 0;
  car.timer = 0;

  while (1) {
    handle_remote_input();
    update_car_position();
    car.timer++;

    if (car.timer % 20 == 0) {
      printf("Car position: (%d, %d)\n", car.x, car.y);
    }
  }

  return 0;
}