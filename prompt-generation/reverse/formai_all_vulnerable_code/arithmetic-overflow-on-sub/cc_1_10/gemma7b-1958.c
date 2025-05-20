//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

typedef struct Vehicle {
  int x, y, direction, speed;
  char status;
} Vehicle;

Vehicle vehicle;

void update_vehicle() {
  switch (vehicle.direction) {
    case 0:
      vehicle.x++;
      break;
    case 1:
      vehicle.y++;
      break;
    case 2:
      vehicle.x--;
      break;
    case 3:
      vehicle.y--;
      break;
  }

  if (vehicle.speed > MAX_SPEED) {
    vehicle.speed = MAX_SPEED;
  }

  vehicle.status = 'A';
}

int main() {
  vehicle.x = 0;
  vehicle.y = 0;
  vehicle.direction = 0;
  vehicle.speed = 5;
  vehicle.status = 'S';

  time_t t = time(NULL);

  while (vehicle.status == 'S') {
    update_vehicle();
    sleep(1);

    if (time(NULL) - t >= 3) {
      vehicle.status = 'A';
    }

    t = time(NULL);
  }

  return 0;
}