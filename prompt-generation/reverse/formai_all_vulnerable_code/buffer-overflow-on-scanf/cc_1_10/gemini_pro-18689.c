//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100
#define MAX_TURN_ANGLE 90

typedef struct {
  int speed;
  int turn_angle;
} RC_Car;

void init_car(RC_Car *car) {
  car->speed = 0;
  car->turn_angle = 0;
}

void print_car_status(RC_Car *car) {
  printf("Speed: %d, Turn angle: %d\n", car->speed, car->turn_angle);
}

void accelerate(RC_Car *car, int amount) {
  car->speed += amount;
  if (car->speed > MAX_SPEED) {
    car->speed = MAX_SPEED;
  }
}

void decelerate(RC_Car *car, int amount) {
  car->speed -= amount;
  if (car->speed < 0) {
    car->speed = 0;
  }
}

void turn_left(RC_Car *car, int angle) {
  car->turn_angle -= angle;
  if (car->turn_angle < -MAX_TURN_ANGLE) {
    car->turn_angle = -MAX_TURN_ANGLE;
  }
}

void turn_right(RC_Car *car, int angle) {
  car->turn_angle += angle;
  if (car->turn_angle > MAX_TURN_ANGLE) {
    car->turn_angle = MAX_TURN_ANGLE;
  }
}

int main() {
  RC_Car car;
  int command;

  init_car(&car);

  while (1) {
    printf("Enter command (1-5): ");
    scanf("%d", &command);

    switch (command) {
      case 1:
        accelerate(&car, 10);
        break;
      case 2:
        decelerate(&car, 10);
        break;
      case 3:
        turn_left(&car, 10);
        break;
      case 4:
        turn_right(&car, 10);
        break;
      case 5:
        exit(0);
    }

    print_car_status(&car);
  }

  return 0;
}