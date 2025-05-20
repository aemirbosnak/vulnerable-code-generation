//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_VEHICLES 4
#define MAX_SPEED 50

typedef struct {
    int vehicle_id;
    int x_pos;
    int y_pos;
    int speed;
} Vehicle;

Vehicle vehicles[NUM_VEHICLES];

void *run_vehicle(void *arg) {
    int vehicle_id = *(int*)arg;
    int speed = vehicles[vehicle_id].speed;

    while (1) {
        if (speed < MAX_SPEED) {
            speed += 1;
            vehicles[vehicle_id].speed = speed;
        } else {
            speed = MAX_SPEED;
            vehicles[vehicle_id].speed = speed;
        }

        printf("Vehicle %d moving at speed %d\n", vehicle_id, speed);
        sleep(1);
    }
}

int main() {
    srand(time(0));

    pthread_t threads[NUM_VEHICLES];
    int vehicle_ids[NUM_VEHICLES] = {1, 2, 3, 4};

    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_create(&threads[i], NULL, run_vehicle, &vehicle_ids[i]);
    }

    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}