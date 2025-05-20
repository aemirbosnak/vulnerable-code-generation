//Code Llama-13B DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
/*
 * Traffic Flow Simulation
 *
 * A program that simulates the flow of traffic on a road network.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 1000
#define CAR_COUNT 100
#define TIME_STEP 1

struct Car {
  int id;
  int speed;
  int lane;
  int pos;
};

struct Road {
  int length;
  int lanes;
  struct Car *cars[ROAD_LENGTH];
};

struct Road road = {
  .length = ROAD_LENGTH,
  .lanes = 3,
  .cars = {NULL}
};

void addCar(int id, int speed, int lane, int pos) {
  struct Car *car = malloc(sizeof(struct Car));
  car->id = id;
  car->speed = speed;
  car->lane = lane;
  car->pos = pos;
  road.cars[pos] = car;
}

void moveCars(int time_step) {
  for (int i = 0; i < ROAD_LENGTH; i++) {
    struct Car *car = road.cars[i];
    if (car != NULL) {
      car->pos += car->speed * time_step;
      if (car->pos >= ROAD_LENGTH) {
        car->pos = 0;
      }
    }
  }
}

void printRoad() {
  printf("Road: ");
  for (int i = 0; i < ROAD_LENGTH; i++) {
    struct Car *car = road.cars[i];
    if (car != NULL) {
      printf("|");
    } else {
      printf("-");
    }
  }
  printf("\n");
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < CAR_COUNT; i++) {
    addCar(i, rand() % 10 + 1, rand() % 3, rand() % ROAD_LENGTH);
  }

  while (1) {
    moveCars(TIME_STEP);
    printRoad();
    sleep(1);
  }

  return 0;
}