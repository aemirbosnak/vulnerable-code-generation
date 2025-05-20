//Code Llama-13B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Alan Turing
/*
 * Traffic Flow Simulation Program
 * Author: Alan Turing
 * Date: 2023-02-11
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_LANES 4
#define MIN_SPEED 20
#define MAX_SPEED 50
#define TIME_STEP 10

typedef struct {
    int id;
    int speed;
    int lane;
} Car;

void simulateTraffic(int numCars) {
    srand(time(NULL));

    Car cars[numCars];
    for (int i = 0; i < numCars; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        cars[i].lane = rand() % MAX_LANES;
    }

    for (int i = 0; i < numCars; i++) {
        printf("Car %d is in lane %d and is traveling at %d km/h\n", cars[i].id, cars[i].lane, cars[i].speed);
    }

    for (int i = 0; i < numCars; i++) {
        cars[i].lane = (cars[i].lane + 1) % MAX_LANES;
    }

    for (int i = 0; i < numCars; i++) {
        printf("Car %d is now in lane %d\n", cars[i].id, cars[i].lane);
    }

    for (int i = 0; i < numCars; i++) {
        cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
    }

    for (int i = 0; i < numCars; i++) {
        printf("Car %d is now traveling at %d km/h\n", cars[i].id, cars[i].speed);
    }
}

int main() {
    int numCars;
    printf("Enter the number of cars: ");
    scanf("%d", &numCars);

    simulateTraffic(numCars);

    return 0;
}