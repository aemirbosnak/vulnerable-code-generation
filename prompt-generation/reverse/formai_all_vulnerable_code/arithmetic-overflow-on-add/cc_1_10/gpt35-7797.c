//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Function to print traffic light state
void printState(int state) {
    switch (state) {
        case RED:
            printf("RED\n");
            break;
        case YELLOW:
            printf("YELLOW\n");
            break;
        case GREEN:
            printf("GREEN\n");
            break;
        default:
            printf("Invalid state\n");
            break;
    }
}

// Function to sleep for specified number of seconds
void sleep(int seconds) {
    clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_time);
}

int main() {
    int state = RED; // Start with red light
    int time_count = 0; // Initialize time counter
    
    while (1) { // Loop indefinitely
        switch(state) {
            case RED:
                printf("RED LIGHT\n");
                sleep(5); // Stay red for 5 seconds
                state = GREEN; // Change to green
                break;
            case YELLOW:
                printf("YELLOW LIGHT\n");
                sleep(2); // Stay yellow for 2 seconds
                state = RED; // Change to red
                break;
            case GREEN:
                printf("GREEN LIGHT\n");
                sleep(10); // Stay green for 10 seconds
                state = YELLOW; // Change to yellow
                break;
            default:
                printf("Invalid state\n");
                break;
        }
        printf("Time elapsed: %d\n", time_count);
        printState(state);
        time_count += 1;
        printf("-----------------\n");
        
        // Uncomment to exit after 20 iterations
        /*
        if (time_count >= 20) {
            break;
        }
        */
    }
    return 0;
}