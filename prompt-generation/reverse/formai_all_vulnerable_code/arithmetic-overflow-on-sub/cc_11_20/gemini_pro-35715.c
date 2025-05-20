//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Traffic light colors
#define RED_LIGHT "\033[31m[RED]\033[0m"
#define YELLOW_LIGHT "\033[33m[YELLOW]\033[0m"
#define GREEN_LIGHT "\033[32m[GREEN]\033[0m"

// Traffic light timings (in seconds)
#define RED_TIME 10
#define YELLOW_TIME 5
#define GREEN_TIME 15

// Main function
int main() {
    // Set up the traffic light
    int state = RED;
    struct timeval start_time;
    struct timeval current_time;

    // Get the current time
    gettimeofday(&start_time, NULL);

    // Main loop
    while (1) {
        // Get the current time
        gettimeofday(&current_time, NULL);

        // Calculate the time elapsed since the start time
        long elapsed_time = (current_time.tv_sec - start_time.tv_sec) * 1000 + (current_time.tv_usec - start_time.tv_usec) / 1000;

        // Update the traffic light state
        if (elapsed_time >= RED_TIME && state == RED) {
            state = YELLOW;
            start_time = current_time;
        } else if (elapsed_time >= YELLOW_TIME && state == YELLOW) {
            state = GREEN;
            start_time = current_time;
        } else if (elapsed_time >= GREEN_TIME && state == GREEN) {
            state = RED;
            start_time = current_time;
        }

        // Print the traffic light state
        switch (state) {
            case RED:
                printf("%s\n", RED_LIGHT);
                break;
            case YELLOW:
                printf("%s\n", YELLOW_LIGHT);
                break;
            case GREEN:
                printf("%s\n", GREEN_LIGHT);
                break;
        }

        //usleep(100000);
    }

    return 0;
}