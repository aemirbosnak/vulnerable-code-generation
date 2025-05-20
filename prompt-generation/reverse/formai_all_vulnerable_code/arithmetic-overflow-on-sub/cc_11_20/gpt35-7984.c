//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define the traffic light timings
#define RED_TIME 5
#define YELLOW_TIME 2
#define GREEN_TIME 8

int main() {

    // Initiate random number generator for testing purposes
    srand(time(0));

    // Initialize the traffic light state
    int traffic_light = RED;

    // Infinite loop for traffic light control
    while (1) {
        unsigned int time_elapsed = 0;

        // Set the traffic light colors and corresponding timings
        switch (traffic_light) {
            case RED:
                printf("Traffic Light: RED\n");
                time_elapsed = RED_TIME;
                break;
            case YELLOW:
                printf("Traffic Light: YELLOW\n");
                time_elapsed = YELLOW_TIME;
                break;
            case GREEN:
                printf("Traffic Light: GREEN\n");
                time_elapsed = GREEN_TIME;
                break;
        }

        // Wait for the traffic light to change state
        unsigned int start_time = 0;
        while (time_elapsed > 0) {
            if (start_time == 0) {
                start_time = time(NULL);
            } else {
                time_t current_time = time(NULL);
                time_elapsed -= (current_time - start_time);
                start_time = current_time;
            }
        }

        // Change the traffic light to the next state
        switch (traffic_light) {
            case RED:
                traffic_light = YELLOW;
                break;
            case YELLOW:
                // Randomly choose the next state between red and green
                if (rand() % 2 == 0) {
                    traffic_light = RED;
                } else {
                    traffic_light = GREEN;
                }
                break;
            case GREEN:
                traffic_light = YELLOW;
                break;
        }
    }

    return 0;
}