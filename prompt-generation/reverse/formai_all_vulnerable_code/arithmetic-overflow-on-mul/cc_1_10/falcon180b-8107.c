//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#define NUM_LANES 4
#define GREEN_TIME 10
#define YELLOW_TIME 3
#define RED_TIME 20
#define TOTAL_TIME (GREEN_TIME + YELLOW_TIME + RED_TIME)

typedef struct {
    int id;
    bool green;
    bool yellow;
    bool red;
} Lane;

Lane lanes[NUM_LANES];

void *trafficLightController(void *laneId) {
    int lane = *(int *) laneId;
    srand(time(NULL) * lane);

    while (true) {
        lanes[lane].green = false;
        lanes[lane].yellow = false;
        lanes[lane].red = false;

        int randomTime = rand() % TOTAL_TIME;

        if (randomTime < GREEN_TIME) {
            lanes[lane].green = true;
        } else if (randomTime < (GREEN_TIME + YELLOW_TIME)) {
            lanes[lane].yellow = true;
        } else {
            lanes[lane].red = true;
        }

        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_LANES];

    for (int i = 0; i < NUM_LANES; i++) {
        pthread_create(&threads[i], NULL, trafficLightController, (void *) &i);
    }

    for (int i = 0; i < NUM_LANES; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}