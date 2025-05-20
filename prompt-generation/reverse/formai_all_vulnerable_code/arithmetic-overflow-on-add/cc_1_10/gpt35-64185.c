//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define the traffic light timings
#define RED_TIME 10
#define YELLOW_TIME 5
#define GREEN_TIME 10

// Define a function to pause the program for a given number of seconds
void pause(int seconds) {
    int milli_seconds = 1000 * seconds; 
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    int current_state = RED;
    int time_remaining = RED_TIME;

    // Loop forever
    while (1) {
        // Print the current state and time remaining
        if (current_state == RED) {
            printf("Red light: %d seconds remaining\n", time_remaining); 
        } else if (current_state == YELLOW) {
            printf("Yellow light: %d seconds remaining\n", time_remaining); 
        } else if (current_state == GREEN) {
            printf("Green light: %d seconds remaining\n", time_remaining); 
        }

        // Decrement the time remaining
        time_remaining--;

        // If the time has expired, switch to the next state
        if (time_remaining == 0) {
            if (current_state == RED) {
                current_state = GREEN;
                time_remaining = GREEN_TIME;
            } else if (current_state == GREEN) {
                current_state = YELLOW;
                time_remaining = YELLOW_TIME;
            } else if (current_state == YELLOW) {
                current_state = RED;
                time_remaining = RED_TIME;
            }
        }

        // Pause for one second
        pause(1);
    }

    return 0;
}