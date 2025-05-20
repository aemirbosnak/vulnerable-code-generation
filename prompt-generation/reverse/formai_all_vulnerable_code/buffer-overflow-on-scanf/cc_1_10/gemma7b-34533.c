//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WHEELS 4
#define MAX_SPEED 10

typedef struct Vehicle {
  int x, y, facing;
  int speed;
  int wheels[NUM_WHEELS];
} Vehicle;

Vehicle create_vehicle() {
  Vehicle v;
  v.x = 0;
  v.y = 0;
  v.facing = 0;
  v.speed = 0;
  for (int i = 0; i < NUM_WHEELS; i++) {
    v.wheels[i] = 0;
  }
  return v;
}

void move_vehicle(Vehicle *v, int dx, int dy) {
  v->x += dx;
  v->y += dy;
}

void turn_vehicle(Vehicle *v, int angle) {
  v->facing += angle;
}

void accelerate(Vehicle *v) {
  v->speed++;
}

void decelerate(Vehicle *v) {
  v->speed--;
}

int main() {
  Vehicle car = create_vehicle();

  // Simulate remote control
  int command;
  while (1) {
    printf("Enter command (a/d/s/r/q): ");
    scanf("%d", &command);

    switch (command) {
      case 1:
        accelerate(&car);
        break;
      case 2:
        decelerate(&car);
        break;
      case 3:
        move_vehicle(&car, 1, 0);
        break;
      case 4:
        move_vehicle(&car, -1, 0);
        break;
      case 5:
        move_vehicle(&car, 0, 1);
        break;
      case 6:
        move_vehicle(&car, 0, -1);
        break;
      case 7:
        turn_vehicle(&car, 1);
        break;
      case 8:
        turn_vehicle(&car, -1);
        break;
      case 9:
        printf("Current position: (%d, %d)\n", car.x, car.y);
        break;
      case 10:
        exit(0);
    }
  }

  return 0;
}