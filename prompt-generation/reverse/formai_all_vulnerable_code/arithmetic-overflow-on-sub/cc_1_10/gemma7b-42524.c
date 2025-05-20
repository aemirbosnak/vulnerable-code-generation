//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Cars 10
#define MAX_Lights 5

typedef struct Car {
  int position;
  int direction;
  int speed;
} Car;

typedef struct Light {
  int status;
  int timer;
} Light;

Car cars[MAX_Cars];
Light lights[MAX_Lights];

void initializeCars() {
  for (int i = 0; i < MAX_Cars; i++) {
    cars[i].position = rand() % MAX_Lights;
    cars[i].direction = rand() % 2;
    cars[i].speed = rand() % 5;
  }
}

void simulateTrafficFlow() {
  time_t start = time(NULL);
  int elapsedTime = 0;

  while (elapsedTime < 60) {
    for (int i = 0; i < MAX_Cars; i++) {
      switch (cars[i].direction) {
        case 0:
          cars[i].position++;
          break;
        case 1:
          cars[i].position--;
          break;
      }

      cars[i].position = (cars[i].position < 0) ? MAX_Lights - 1 : (cars[i].position >= MAX_Lights) ? 0 : cars[i].position;
    }

    for (int i = 0; i < MAX_Lights; i++) {
      lights[i].status = (lights[i].timer == 0) ? 1 : 0;
      lights[i].timer++;
    }

    elapsedTime = time(NULL) - start;
  }

  for (int i = 0; i < MAX_Cars; i++) {
    printf("Car %d position: %d, direction: %d, speed: %d\n", i, cars[i].position, cars[i].direction, cars[i].speed);
  }

  printf("Traffic light status:\n");
  for (int i = 0; i < MAX_Lights; i++) {
    printf("Light %d status: %d\n", i, lights[i].status);
  }
}

int main() {
  initializeCars();
  simulateTrafficFlow();

  return 0;
}