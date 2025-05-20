//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: introspective
// This program simulates a traffic light controller.
// It controls the traffic lights at an intersection.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Define the states of the traffic lights
#define GREEN 0
#define YELLOW 1
#define RED 2

// Define the duration of each light cycle
#define LIGHT_DURATION 15

void set_light(int light_state) {
    printf("Setting light to %d\n", light_state);
}

void main() {
    // Initialize the traffic light states
    int red_light = GREEN;
    int yellow_light = GREEN;
    int green_light = GREEN;

    // Initialize the current time
    clock_t start_time;
    start_time = clock();

    // Loop indefinitely
    while (1) {
        // Set the red light
        set_light(RED);

        // Wait for 5 seconds
        sleep(5);

        // Set the yellow light
        set_light(YELLOW);

        // Wait for 1 second
        sleep(1);

        // Set the green light
        set_light(GREEN);

        // Wait for 15 seconds
        sleep(LIGHT_DURATION);

        // Reset the light states
        red_light = GREEN;
        yellow_light = GREEN;
        green_light = GREEN;

        // Get the current time
        clock_t current_time;
        current_time = clock();

        // Calculate the duration of the light cycle
        double duration = (double)(current_time - start_time) / CLOCKS_PER_SEC;

        // Print the duration of the light cycle
        printf("Duration: %f seconds\n", duration);

        // Reset the start time
        start_time = clock();
    }
}