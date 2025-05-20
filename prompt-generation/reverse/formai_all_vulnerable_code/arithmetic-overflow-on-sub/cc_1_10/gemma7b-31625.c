//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int lane;
  int position;
  int speed;
} Car;

void simulateTrafficFlow(Car cars[], int numCars) {
  time_t start = time(NULL);
  int i, j;

  for (i = 0; i < numCars; i++) {
    cars[i].position = 0;
    cars[i].speed = rand() % 3 + 1;
  }

  while (time(NULL) - start < 10) {
    for (i = 0; i < numCars; i++) {
      cars[i].position += cars[i].speed;

      if (cars[i].position >= MAX_LANE) {
        cars[i].position = MAX_LANE - 1;
        cars[i].speed = -cars[i].speed;
      } else if (cars[i].position <= 0) {
        cars[i].position = 0;
        cars[i].speed = -cars[i].speed;
      }
    }

    sleep(1);
  }

  for (i = 0; i < numCars; i++) {
    printf("Car %d position: %d\n", i, cars[i].position);
  }
}

int main() {
  Car cars[MAX_CARS];
  int numCars = 5;

  simulateTrafficFlow(cars, numCars);

  return 0;
}