//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SPEED 10
#define TURN_RADIUS 20

struct Vehicle {
  int x;
  int y;
  int direction;
  int speed;
};

void moveVehicle(struct Vehicle *vehicle) {
  switch (vehicle->direction) {
    case 0:
      vehicle->x++;
      break;
    case 1:
      vehicle->y++;
      break;
    case 2:
      vehicle->x--;
      break;
    case 3:
      vehicle->y--;
      break;
  }

  vehicle->speed++;

  if (vehicle->speed > MAX_SPEED) {
    vehicle->speed = MAX_SPEED;
  }
}

int main() {
  struct Vehicle vehicle;
  vehicle.x = 0;
  vehicle.y = 0;
  vehicle.direction = 0;
  vehicle.speed = 0;

  time_t start = time(NULL);

  while (time(NULL) - start < 10) {
    moveVehicle(&vehicle);
    printf("x: %d, y: %d, direction: %d, speed: %d\n", vehicle.x, vehicle.y, vehicle.direction, vehicle.speed);
    sleep(0.1);
  }

  return 0;
}