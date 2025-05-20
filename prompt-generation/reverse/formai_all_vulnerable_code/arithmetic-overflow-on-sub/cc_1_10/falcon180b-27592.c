//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3
#define PEDESTRIAN_RED 4
#define PEDESTRIAN_GREEN 5
#define NUM_STATES 6

#define LIGHT_DELAY 5
#define PEDESTRIAN_DELAY 15

int main() {
    int state = RED;
    int pedestrian_state = PEDESTRIAN_RED;
    int count = 0;
    time_t start_time = time(NULL);

    while (1) {
        printf("State: %d\n", state);
        printf("Pedestrian State: %d\n", pedestrian_state);
        printf("Count: %d\n", count);

        if (state == RED) {
            printf("Traffic light is red. Stopping traffic.\n");
        } else if (state == YELLOW) {
            printf("Traffic light is yellow. Slow down.\n");
        } else if (state == GREEN) {
            printf("Traffic light is green. Go!\n");
        } else if (state == PEDESTRIAN_RED) {
            printf("Pedestrians must stop.\n");
        } else if (state == PEDESTRIAN_GREEN) {
            printf("Pedestrians may cross.\n");
        }

        if (count == 0) {
            state = (state + 1) % NUM_STATES;
            count = LIGHT_DELAY;
        } else {
            count--;
        }

        if (pedestrian_state == PEDESTRIAN_RED) {
            pedestrian_state = (pedestrian_state + 1) % NUM_STATES;
            count = PEDESTRIAN_DELAY;
        } else {
            count--;
        }

        time_t current_time = time(NULL);
        if (current_time - start_time > 60) {
            start_time = current_time;
            printf("Time reset!\n");
        }

        sleep(1);
    }

    return 0;
}