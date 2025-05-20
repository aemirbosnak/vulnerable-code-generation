//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define the duration of each traffic light state
#define RED_DURATION 10
#define YELLOW_DURATION 3
#define GREEN_DURATION 20

// Define the total duration of the traffic light cycle
#define CYCLE_DURATION (RED_DURATION + YELLOW_DURATION + GREEN_DURATION)

void traffic_light_controller(void) {
    int curr_state = RED;
    int next_state = GREEN;
    time_t curr_time = time(NULL);
    time_t next_time = curr_time + RED_DURATION;

    while (1) {
        if (difftime(curr_time, next_time) <= 0) {
            // Switch to the next traffic light state
            curr_state = next_state;
            next_state = (next_state == GREEN)? RED : GREEN;
            next_time = curr_time + (next_state == RED)? RED_DURATION : GREEN_DURATION;
        }

        // Print the current traffic light state
        switch (curr_state) {
            case RED:
                printf("Traffic light is red\n");
                break;
            case YELLOW:
                printf("Traffic light is yellow\n");
                break;
            case GREEN:
                printf("Traffic light is green\n");
                break;
        }

        // Wait for the next state change
        curr_time = time(NULL);
    }
}

int main(void) {
    traffic_light_controller();
    return 0;
}