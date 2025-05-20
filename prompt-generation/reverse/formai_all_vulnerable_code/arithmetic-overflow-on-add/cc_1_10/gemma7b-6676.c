//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
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

void simulateTrafficFlow(Car cars[], int numCars, int roadLength) {
    int i, j, t, step;
    time_t start, end;

    start = time(NULL);
    end = start + 60;

    for (step = 0; time(NULL) < end; step++) {
        for (i = 0; i < numCars; i++) {
            switch (cars[i].direction) {
                case 0:
                    cars[i].position++;
                    if (cars[i].position == roadLength) {
                        cars[i].direction = 1;
                    }
                    break;
                case 1:
                    cars[i].position--;
                    if (cars[i].position == 0) {
                        cars[i].direction = 0;
                    }
                    break;
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
    int roadLength = MAX_ROAD_LENGTH;

    for (int i = 0; i < numCars; i++) {
        cars[i].position = rand() % roadLength;
        cars[i].direction = rand() % 2;
        cars[i].speed = rand() % 5;
    }

    simulateTrafficFlow(cars, numCars, roadLength);

    return 0;
}