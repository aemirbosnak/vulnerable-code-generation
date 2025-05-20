//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: minimalist
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20

typedef struct Car {
  int x, y, dir, speed;
  struct Car* next;
} Car;

Car* createCar(int x, int y, int dir, int speed) {
  Car* car = malloc(sizeof(Car));
  car->x = x;
  car->y = y;
  car->dir = dir;
  car->speed = speed;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow(Car* cars) {
  time_t t = time(NULL);
  while (time(NULL) - t < 10) {
    for (Car* car = cars; car; car = car->next) {
      switch (car->dir) {
        case 0: // North
          car->y++;
          break;
        case 1: // East
          car->x++;
          break;
        case 2: // South
          car->y--;
          break;
        case 3: // West
          car->x--;
          break;
      }
      car->speed--;
    }
    sleep(1);
  }
}

int main() {
  Car* cars = createCar(0, 0, 0, 5);
  cars = createCar(10, 0, 1, 4);
  cars = createCar(20, 0, 2, 3);
  simulateTrafficFlow(cars);
  return 0;
}