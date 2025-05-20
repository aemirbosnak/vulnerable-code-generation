//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the states of the traffic light
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

// Define the duration of each light in seconds
#define RED_LIGHT_DURATION 15
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 30

int main() {
    int current_light = RED_LIGHT;
    time_t start_time, end_time;

    // Seed the random number generator
    srand(time(NULL));

    // Start the traffic light
    start_time = time(NULL);

    // Loop until the program is interrupted
    while (1) {
        // Check if it's time to change the light
        end_time = time(NULL);
        if (difftime(end_time, start_time) >= GREEN_LIGHT_DURATION) {
            current_light = (current_light + 1) % 3;
            start_time = end_time;
        }

        // Print the current light
        printf("Current light: ");
        switch (current_light) {
            case RED_LIGHT:
                printf("red\n");
                break;
            case YELLOW_LIGHT:
                printf("yellow\n");
                break;
            case GREEN_LIGHT:
                printf("green\n");
                break;
        }

        // Wait for the next second
        time_t next_second = time(NULL) + 1;
        while (difftime(next_second, time(NULL)) > 0) {
            usleep(100000); // Sleep for 100ms
        }
    }

    return 0;
}