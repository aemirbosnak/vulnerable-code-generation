//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int x, y, speed, direction, lane;
} Car;

void simulateTrafficFlow(int num_cars) {
    Car cars[num_cars];

    for (int i = 0; i < num_cars; i++) {
        cars[i].x = rand() % MAX_LANE;
        cars[i].y = rand() % MAX_LANE;
        cars[i].speed = rand() % 3;
        cars[i].direction = rand() % 4;
        cars[i].lane = rand() % MAX_LANE;
    }

    time_t start_time = time(NULL);
    time_t current_time = time(NULL);

    while (current_time - start_time < 10) {
        for (int i = 0; i < num_cars; i++) {
            switch (cars[i].direction) {
                case 0:
                    cars[i].x++;
                    break;
                case 1:
                    cars[i].x--;
                    break;
                case 2:
                    cars[i].y++;
                    break;
                case 3:
                    cars[i].y--;
                    break;
            }

            if (cars[i].x >= MAX_LANE || cars[i].x < 0) {
                cars[i].direction = (cars[i].direction + 1) % 4;
            }

            if (cars[i].y >= MAX_LANE || cars[i].y < 0) {
                cars[i].direction = (cars[i].direction + 1) % 4;
            }
        }

        current_time = time(NULL);
    }

    for (int i = 0; i < num_cars; i++) {
        printf("Car %d: x = %d, y = %d, lane = %d\n", i + 1, cars[i].x, cars[i].y, cars[i].lane);
    }
}

int main() {
    simulateTrafficFlow(5);

    return 0;
}