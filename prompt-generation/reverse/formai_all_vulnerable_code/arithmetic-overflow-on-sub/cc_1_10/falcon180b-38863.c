//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the traffic light states
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

// Define the duration of each traffic light state in seconds
#define RED_LIGHT_DURATION 5
#define YELLOW_LIGHT_DURATION 3
#define GREEN_LIGHT_DURATION 7

// Define the total duration of the traffic light cycle in seconds
#define TOTAL_CYCLE_DURATION (RED_LIGHT_DURATION + YELLOW_LIGHT_DURATION + GREEN_LIGHT_DURATION)

int main() {
    // Initialize the traffic light state
    int traffic_light_state = RED_LIGHT;

    // Initialize the time for the current traffic light state
    time_t current_time;
    time(&current_time);

    // Loop through the traffic light cycle
    while (1) {
        // Check if it's time to change the traffic light state
        time_t elapsed_time = difftime(time(NULL), current_time);
        if (elapsed_time >= TOTAL_CYCLE_DURATION) {
            current_time = time(NULL);

            // Change to the next traffic light state
            switch (traffic_light_state) {
                case RED_LIGHT:
                    traffic_light_state = YELLOW_LIGHT;
                    break;
                case YELLOW_LIGHT:
                    traffic_light_state = GREEN_LIGHT;
                    break;
                case GREEN_LIGHT:
                    traffic_light_state = RED_LIGHT;
                    break;
            }
        }

        // Print the current traffic light state
        printf("Current traffic light state: ");
        switch (traffic_light_state) {
            case RED_LIGHT:
                printf("Red\n");
                break;
            case YELLOW_LIGHT:
                printf("Yellow\n");
                break;
            case GREEN_LIGHT:
                printf("Green\n");
                break;
        }

        // Wait for the remaining time in the current traffic light state
        time_t remaining_time = TOTAL_CYCLE_DURATION - elapsed_time;
        if (remaining_time > 0) {
            sleep(remaining_time);
        }
    }

    return 0;
}