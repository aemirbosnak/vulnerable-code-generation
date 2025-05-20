//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define NUM_CARS 10

typedef struct Car {
    int lane;
    int speed;
    int position;
    int direction;
} Car;

Car cars[NUM_CARS];

void simulateTrafficFlow() {
    time_t tStart = time(NULL);
    int elapsedTime = 0;

    while (elapsedTime < 60) {
        for (int i = 0; i < NUM_CARS; i++) {
            cars[i].position++;

            if (cars[i].position >= NUM_LANES * 10) {
                cars[i].direction *= -1;
                cars[i].position = 0;
            }

            if (cars[i].direction == 1) {
                cars[i].lane++;
            } else if (cars[i].direction == -1) {
                cars[i].lane--;
            }
        }

        elapsedTime = time(NULL) - tStart;
    }
}

int main() {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].lane = rand() % NUM_LANES;
        cars[i].speed = rand() % 5;
        cars[i].position = rand() % (NUM_LANES * 10);
        cars[i].direction = rand() % 2;
    }

    simulateTrafficFlow();

    return 0;
}