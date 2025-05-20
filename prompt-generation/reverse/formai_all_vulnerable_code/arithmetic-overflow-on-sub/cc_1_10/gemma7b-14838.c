//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRAFFIC_LIGHT_COUNT 5
#define MAX_CARS_COUNT 10

typedef struct Car {
  int currentPosition;
  int targetPosition;
  int speed;
} Car;

typedef struct TrafficLight {
  int currentStatus;
  int nextStatus;
  int timer;
} TrafficLight;

TrafficLight trafficLights[MAX_TRAFFIC_LIGHT_COUNT];
Car cars[MAX_CARS_COUNT];

void initializeTrafficLights() {
  for (int i = 0; i < MAX_TRAFFIC_LIGHT_COUNT; i++) {
    trafficLights[i].currentStatus = 0;
    trafficLights[i].nextStatus = 1;
    trafficLights[i].timer = 0;
  }
}

void initializeCars() {
  for (int i = 0; i < MAX_CARS_COUNT; i++) {
    cars[i].currentPosition = 0;
    cars[i].targetPosition = 10;
    cars[i].speed = 2;
  }
}

void simulateTrafficFlow() {
  time_t t = time(NULL);
  int elapsedTime = 0;

  while (elapsedTime < 10) {
    for (int i = 0; i < MAX_TRAFFIC_LIGHT_COUNT; i++) {
      trafficLights[i].timer++;

      if (trafficLights[i].timer == trafficLights[i].nextStatus) {
        trafficLights[i].currentStatus = trafficLights[i].nextStatus;
        trafficLights[i].timer = 0;
      }
    }

    for (int i = 0; i < MAX_CARS_COUNT; i++) {
      cars[i].currentPosition += cars[i].speed;

      if (cars[i].currentPosition == cars[i].targetPosition) {
        cars[i].speed = -2;
      }
    }

    elapsedTime = time(NULL) - t;
  }
}

int main() {
  initializeTrafficLights();
  initializeCars();
  simulateTrafficFlow();

  return 0;
}