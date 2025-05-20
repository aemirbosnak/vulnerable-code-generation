//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the states of the traffic light
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define the duration of each state in seconds
#define RED_DURATION 5
#define YELLOW_DURATION 2
#define GREEN_DURATION 10

// Define the total duration of the traffic light cycle in seconds
#define TOTAL_DURATION (RED_DURATION + YELLOW_DURATION + GREEN_DURATION)

// Define the number of cars allowed to pass during the green phase
#define MAX_CARS 5

int main() {
    int state = RED;
    int cars_passed = 0;
    time_t start_time = time(NULL);

    // Simulate the traffic light cycle
    while (1) {
        if (state == RED) {
            printf("Traffic light is RED\n");
            if (time(NULL) - start_time >= RED_DURATION) {
                state = YELLOW;
                start_time = time(NULL);
                cars_passed = 0;
            }
        } else if (state == YELLOW) {
            printf("Traffic light is YELLOW\n");
            if (time(NULL) - start_time >= YELLOW_DURATION) {
                state = GREEN;
                start_time = time(NULL);
                cars_passed = 0;
            }
        } else if (state == GREEN) {
            printf("Traffic light is GREEN\n");
            if (time(NULL) - start_time >= GREEN_DURATION) {
                state = RED;
                start_time = time(NULL);
                cars_passed = 0;
            } else if (cars_passed >= MAX_CARS) {
                state = YELLOW;
                start_time = time(NULL);
                cars_passed = 0;
            } else if (cars_passed < MAX_CARS) {
                cars_passed++;
                printf("A car has passed\n");
            }
        }

        if (state == RED) {
            printf("Traffic light is RED\n");
        } else if (state == YELLOW) {
            printf("Traffic light is YELLOW\n");
        } else if (state == GREEN) {
            printf("Traffic light is GREEN\n");
        }
    }

    return 0;
}