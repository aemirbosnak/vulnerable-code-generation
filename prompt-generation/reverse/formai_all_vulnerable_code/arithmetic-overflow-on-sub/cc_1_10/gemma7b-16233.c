//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: real-life
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 10

typedef struct Car {
    int lane;
    int speed;
    int position;
    int direction;
} Car;

Car cars[NUM_CARS];

void initializeCars() {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].lane = rand() % NUM_LANE;
        cars[i].speed = rand() % 5 + 1;
        cars[i].position = rand() % 1000;
        cars[i].direction = rand() % 2;
    }
}

void simulateTrafficFlow() {
    time_t start = time(NULL);
    while (time(NULL) - start < 60) {
        for (int i = 0; i < NUM_CARS; i++) {
            switch (cars[i].direction) {
                case 0:
                    cars[i].position += cars[i].speed;
                    if (cars[i].position >= 1000) {
                        cars[i].position = 0;
                        cars[i].lane = rand() % NUM_LANE;
                    }
                    break;
                case 1:
                    cars[i].position -= cars[i].speed;
                    if (cars[i].position <= 0) {
                        cars[i].position = 1000;
                        cars[i].lane = rand() % NUM_LANE;
                    }
                    break;
            }
        }

        sleep(1);
    }
}

int main() {
    initializeCars();
    simulateTrafficFlow();

    return 0;
}