//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: modular
#include <stdlib.h>
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

void initializeCars() {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].lane = rand() % NUM_LANE;
        cars[i].position = rand() % 100;
        cars[i].speed = rand() % 5;
        cars[i].direction = rand() % 2;
    }
}

void simulateTrafficFlow() {
    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (int i = 0; i < NUM_CARS; i++) {
            switch (cars[i].direction) {
                case 0:
                    cars[i].position++;
                    if (cars[i].position >= 100) {
                        cars[i].direction = 1;
                        cars[i].lane = rand() % NUM_LANE;
                        cars[i].position = 0;
                    }
                    break;
                case 1:
                    cars[i].position--;
                    if (cars[i].position <= 0) {
                        cars[i].direction = 0;
                        cars[i].lane = rand() % NUM_LANE;
                        cars[i].position = 100;
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