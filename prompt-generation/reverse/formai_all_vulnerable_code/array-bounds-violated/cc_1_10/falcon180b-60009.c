//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define MAX_LANES 4

typedef struct {
    int id;
    int speed;
    int location;
    int destination;
    int lane;
} Car;

typedef struct {
    int length;
    int lanes;
    int capacity;
} Road;

Road roads[MAX_ROADS];
Car cars[MAX_CARS];

void initRoads() {
    int i;
    for (i = 0; i < MAX_ROADS; i++) {
        roads[i].length = rand() % 1000 + 1000;
        roads[i].lanes = rand() % MAX_LANES + 1;
        roads[i].capacity = roads[i].length * roads[i].lanes;
    }
}

void initCars() {
    int i;
    for (i = 0; i < MAX_CARS; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % 100;
        cars[i].location = 0;
        cars[i].destination = roads[rand() % MAX_ROADS].length;
        cars[i].lane = rand() % roads[cars[i].destination].lanes;
    }
}

void updateCarLocation(int carId) {
    Car *car = &cars[carId];
    int roadId = getRoadId(car->location);
    int roadLength = roads[roadId].length;
    int carSpeed = car->speed;
    int timeToDestination = (car->destination - car->location) / carSpeed;

    if (timeToDestination > 0) {
        car->location += carSpeed;
    } else {
        car->location = car->destination;
        if (car->lane == 0) {
            printf("Car %d has reached destination on road %d\n", carId, roadId);
        }
    }
}

int getRoadId(int location) {
    int i;
    for (i = 0; i < MAX_ROADS; i++) {
        if (location >= roads[i].length) {
            continue;
        }
        return i;
    }
    return -1;
}

int main() {
    srand(time(NULL));
    initRoads();
    initCars();

    int simulationTime = 0;
    while (simulationTime < 1000) {
        int i;
        for (i = 0; i < MAX_CARS; i++) {
            updateCarLocation(i);
        }
        simulationTime++;
        usleep(10000);
    }

    return 0;
}