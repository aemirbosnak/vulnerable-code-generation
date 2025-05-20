//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the states of the traffic light
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define the duration of each state in seconds
#define RED_DURATION 30
#define YELLOW_DURATION 5
#define GREEN_DURATION 30

int main() {
    int state = RED; // Initialize the traffic light to red
    time_t start_time; // Variable to store the start time
    time_t end_time; // Variable to store the end time

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop indefinitely
    while (1) {
        // Get the current time
        time(&start_time);

        // Generate a random number between 0 and 1
        double random_number = rand() / (double) RAND_MAX;

        // Determine the duration of the current state based on the random number
        if (random_number < 0.33) {
            end_time = start_time + RED_DURATION;
        } else if (random_number < 0.66) {
            end_time = start_time + YELLOW_DURATION;
        } else {
            end_time = start_time + GREEN_DURATION;
        }

        // Change the state of the traffic light
        switch (state) {
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

        // Wait until the end time
        while (difftime(time(NULL), end_time) > 0) {
            // Do nothing
        }

        // Change the state of the traffic light
        switch (state) {
            case RED:
                state = GREEN;
                break;
            case YELLOW:
                state = RED;
                break;
            case GREEN:
                state = YELLOW;
                break;
        }
    }

    return 0;
}