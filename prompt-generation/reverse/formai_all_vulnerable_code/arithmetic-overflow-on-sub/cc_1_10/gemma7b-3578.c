//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS_PER_LANE 10

typedef struct Car {
  int lane;
  int position;
  int speed;
} Car;

Car cars[MAX_CARS_PER_LANE][NUM_LANE];

void initialize_cars() {
  for (int i = 0; i < MAX_CARS_PER_LANE; i++) {
    for (int j = 0; j < NUM_LANE; j++) {
      cars[i][j].lane = -1;
      cars[i][j].position = -1;
      cars[i][j].speed = 0;
    }
  }
}

void simulate_traffic() {
  time_t t = time(NULL);
  int elapsed_time = 0;

  while (elapsed_time < 10) {
    for (int i = 0; i < MAX_CARS_PER_LANE; i++) {
      for (int j = 0; j < NUM_LANE; j++) {
        if (cars[i][j].lane != -1) {
          cars[i][j].position++;
          if (cars[i][j].position >= 100) {
            cars[i][j].lane = -1;
            cars[i][j].position = -1;
          }
        }
      }
    }

    elapsed_time = time(NULL) - t;
    t = time(NULL);
  }
}

int main() {
  initialize_cars();
  simulate_traffic();

  return 0;
}