//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define MAX_PASSENGERS 8
#define MIN_WAIT_TIME 1
#define MAX_WAIT_TIME 5

typedef struct {
    int floor;
    int direction;
} Elevator;

Elevator elevators[NUM_ELEVATORS];
int passengers[NUM_FLOORS];

void initialize() {
    int i, j;

    for (i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = rand() % NUM_FLOORS;
        elevators[i].direction = rand() % 2? 1 : -1;
    }

    for (i = 0; i < NUM_FLOORS; i++) {
        passengers[i] = 0;
    }
}

void simulate() {
    int i, j, k, num_passengers;

    for (k = 0; k < 100; k++) {
        for (i = 0; i < NUM_ELEVATORS; i++) {
            elevators[i].floor += elevators[i].direction;

            if (elevators[i].floor < 0) {
                elevators[i].floor = NUM_FLOORS - 1;
            } else if (elevators[i].floor >= NUM_FLOORS) {
                elevators[i].floor = 0;
            }

            num_passengers = passengers[elevators[i].floor];

            if (num_passengers > 0 && elevators[i].floor == elevators[i].direction > 0? elevators[i].floor : elevators[i].floor - 1) {
                elevators[i].floor += (rand() % 2)? 1 : -1;
                passengers[elevators[i].floor] += num_passengers;
                passengers[elevators[i].floor - (elevators[i].direction > 0? 1 : 0)] -= num_passengers;
            }

            if (elevators[i].floor == elevators[i].direction > 0? elevators[i].floor : elevators[i].floor - 1) {
                elevators[i].direction = elevators[i].direction > 0? -1 : 1;
            }
        }

        for (i = 0; i < NUM_FLOORS; i++) {
            if (passengers[i] > 0) {
                printf("%d: %d passengers waiting\n", i, passengers[i]);
            }
        }

        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    initialize();
    simulate();

    return 0;
}