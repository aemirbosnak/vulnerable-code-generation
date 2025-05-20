//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int position;
    int direction;
    int speed;
    int lane;
} Car;

Car cars[MAX_CARS];

void initializeCars() {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].position = 0;
        cars[i].direction = 1;
        cars[i].speed = 5;
        cars[i].lane = 1;
    }
}

void simulateTrafficFlow() {
    time_t tStart = time(NULL);

    while (time(NULL) - tStart < 10) {
        for (int i = 0; i < MAX_CARS; i++) {
            switch (cars[i].direction) {
                case 1:
                    cars[i].position++;
                    break;
                case -1:
                    cars[i].position--;
                    break;
            }

            if (cars[i].position >= 10) {
                cars[i].direction = -1;
            } else if (cars[i].position <= 0) {
                cars[i].direction = 1;
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