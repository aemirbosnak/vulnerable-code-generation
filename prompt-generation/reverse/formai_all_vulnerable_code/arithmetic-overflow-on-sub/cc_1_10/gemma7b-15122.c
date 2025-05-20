//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_TURN 90

typedef struct Vehicle {
  int x, y, direction, speed;
} Vehicle;

Vehicle vehicle;

void moveVehicle() {
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

  vehicle.speed++;

  if (vehicle.speed >= MAX_SPEED) {
    vehicle.speed = MAX_SPEED;
  }
}

void turnVehicle(int angle) {
  vehicle.direction = (vehicle.direction + angle) % MAX_TURN;
}

int main() {
  vehicle.x = 0;
  vehicle.y = 0;
  vehicle.direction = 0;
  vehicle.speed = 0;

  time_t start = time(NULL);

  while (time(NULL) - start < 10) {
    moveVehicle();
    turnVehicle(rand() % 10);
  }

  printf("X: %d, Y: %d, Direction: %d, Speed: %d\n", vehicle.x, vehicle.y, vehicle.direction, vehicle.speed);

  return 0;
}