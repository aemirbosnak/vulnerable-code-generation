//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_ROAD_LENGTH 100

typedef struct Car {
  int position;
  int direction;
  int speed;
} Car;

Car cars[MAX_CARS];

void update_traffic_flow(void) {
  for (int i = 0; i < MAX_CARS; i++) {
    switch (cars[i].direction) {
      case 1:
        cars[i].position++;
        if (cars[i].position >= MAX_ROAD_LENGTH) {
          cars[i].direction = -1;
        }
        break;
      case -1:
        cars[i].position--;
        if (cars[i].position <= 0) {
          cars[i].direction = 1;
        }
        break;
    }
  }
}

int main() {
  time_t t;
  srand(time(NULL));

  for (int i = 0; i < MAX_CARS; i++) {
    cars[i].position = rand() % MAX_ROAD_LENGTH;
    cars[i].direction = rand() % 2 - 1;
    cars[i].speed = rand() % 5 + 1;
  }

  t = time(NULL);
  while (time(NULL) - t < 10) {
    update_traffic_flow();
    sleep(1);
  }

  return 0;
}