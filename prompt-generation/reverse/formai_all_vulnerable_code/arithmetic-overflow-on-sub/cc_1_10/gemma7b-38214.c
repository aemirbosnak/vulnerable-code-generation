//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

typedef struct Car {
  int position;
  int speed;
  int direction;
} Car;

void simulateTrafficFlow() {
  Car cars[MAX_CARS];
  for (int i = 0; i < MAX_CARS; i++) {
    cars[i].position = rand() % ROAD_LENGTH;
    cars[i].speed = rand() % 5 + 1;
    cars[i].direction = rand() % 2;
  }

  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 60) {
    for (int i = 0; i < MAX_CARS; i++) {
      switch (cars[i].direction) {
        case 0:
          cars[i].position++;
          break;
        case 1:
          cars[i].position--;
          break;
      }

      if (cars[i].position >= ROAD_LENGTH) {
        cars[i].position = 0;
      } else if (cars[i].position <= 0) {
        cars[i].position = ROAD_LENGTH - 1;
      }
    }

    sleep(1);
  }

  for (int i = 0; i < MAX_CARS; i++) {
    printf("Car %d position: %d, speed: %d, direction: %d\n", i, cars[i].position, cars[i].speed, cars[i].direction);
  }
}

int main() {
  simulateTrafficFlow();

  return 0;
}