//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main() {

    // Initialize the traffic light state
    int state = RED;

    // Initialize the duration for each state
    int duration_red = 10;
    int duration_yellow = 5;
    int duration_green = 15;

    // Initialize the timer for each state
    clock_t start_time, end_time;

    // Initialize the seed for random number generator
    srand(time(NULL));

    // Loop until the user wants to exit
    while (1) {

        // Print the current state of the traffic light
        printf("Current state: ");
        switch (state) {
            case RED:
                printf("Red\n");
                break;
            case YELLOW:
                printf("Yellow\n");
                break;
            case GREEN:
                printf("Green\n");
                break;
            default:
                printf("Invalid state\n");
                break;
        }

        // Wait for the duration of the current state
        switch (state) {
            case RED:
                start_time = clock();
                while (clock() - start_time < duration_red * CLOCKS_PER_SEC);
                break;
            case YELLOW:
                start_time = clock();
                while (clock() - start_time < duration_yellow * CLOCKS_PER_SEC);
                break;
            case GREEN:
                start_time = clock();
                while (clock() - start_time < duration_green * CLOCKS_PER_SEC);
                break;
            default:
                break;
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
            default:
                break;
        }

        // Wait for a random duration before changing the state again
        int random_duration = rand() % 5 + 1;
        start_time = clock();
        while (clock() - start_time < random_duration * CLOCKS_PER_SEC);
    }

    return 0;
}