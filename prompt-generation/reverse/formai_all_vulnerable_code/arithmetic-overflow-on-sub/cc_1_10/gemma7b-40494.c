//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define TURN_RADIUS 5

typedef struct Vehicle {
  int x;
  int y;
  int heading;
  int speed;
} Vehicle;

void moveVehicle(Vehicle *vehicle) {
  switch (vehicle->heading) {
    case 0:
      vehicle->x++;
      break;
    case 90:
      vehicle->y++;
      break;
    case 180:
      vehicle->x--;
      break;
    case 270:
      vehicle->y--;
      break;
  }

  vehicle->speed--;
  if (vehicle->speed <= 0) {
    vehicle->speed = 0;
  }
}

int main() {
  Vehicle vehicle;
  vehicle.x = 0;
  vehicle.y = 0;
  vehicle.heading = 0;
  vehicle.speed = MAX_SPEED;

  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 10) {
    moveVehicle(&vehicle);
  }

  printf("X: %d, Y: %d\n", vehicle.x, vehicle.y);

  return 0;
}