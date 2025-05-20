//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 10

typedef struct Car {
    int lane;
    int position;
    int speed;
    int direction;
} Car;

Car cars[NUM_CARS];

void initialize_cars() {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].lane = rand() % NUM_LANE;
        cars[i].position = rand() % 1000;
        cars[i].speed = rand() % 5;
        cars[i].direction = rand() % 2;
    }
}

void simulate_traffic_flow() {
    time_t t = time(NULL);
    int time_elapsed = 0;

    while (time_elapsed < 60) {
        for (int i = 0; i < NUM_CARS; i++) {
            switch (cars[i].direction) {
                case 0:
                    cars[i].position += cars[i].speed;
                    break;
                case 1:
                    cars[i].position -= cars[i].speed;
                    break;
            }

            if (cars[i].position > 1000) {
                cars[i].position = 0;
            } else if (cars[i].position < 0) {
                cars[i].position = 1000;
            }

            printf("Car %d is on lane %d, position %d, speed %d, direction %d\n", i, cars[i].lane, cars[i].position, cars[i].speed, cars[i].direction);
        }

        time_elapsed = time(NULL) - t;
        t = time(NULL);
    }
}

int main() {
    initialize_cars();
    simulate_traffic_flow();

    return 0;
}