//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the states of the traffic light
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

// Define the duration of each light state in seconds
#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 3
#define GREEN_LIGHT_DURATION 20

// Define the total duration of the traffic light cycle in seconds
#define TOTAL_CYCLE_DURATION (RED_LIGHT_DURATION + YELLOW_LIGHT_DURATION + GREEN_LIGHT_DURATION)

int main() {
    int currentState = RED_LIGHT;
    time_t startTime;
    time_t endTime;

    printf("Starting traffic light controller...\n");

    // Get the current time and set the end time for the first cycle
    time(&startTime);
    endTime = startTime + TOTAL_CYCLE_DURATION;

    while (1) {
        // Check if the current time is within the duration of the current state
        time_t currentTime;
        time(&currentTime);

        if (currentTime >= endTime) {
            // Cycle complete, switch to the next state
            switch (currentState) {
                case RED_LIGHT:
                    currentState = GREEN_LIGHT;
                    break;
                case YELLOW_LIGHT:
                    currentState = RED_LIGHT;
                    break;
                case GREEN_LIGHT:
                    currentState = YELLOW_LIGHT;
                    break;
            }

            // Update the end time for the next cycle
            endTime = currentTime + TOTAL_CYCLE_DURATION;
        }

        // Print the current state of the traffic light
        switch (currentState) {
            case RED_LIGHT:
                printf("Traffic light is red\n");
                break;
            case YELLOW_LIGHT:
                printf("Traffic light is yellow\n");
                break;
            case GREEN_LIGHT:
                printf("Traffic light is green\n");
                break;
        }

        // Wait for the remaining time in the current state
        time_t waitTime = endTime - currentTime;
        sleep(waitTime);
    }

    return 0;
}