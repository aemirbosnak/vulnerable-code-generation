//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int greenTime = 20;
    int yellowTime = 5;
    int redTime = 30;
    int currentState = 0;
    time_t startTime = 0;
    int timeRemaining = 0;

    // Initialize random seed
    srand(time(NULL));

    // Start timer
    startTime = time(NULL);

    // Loop until user exits program
    while(1) {
        // Get current time
        time_t currentTime = time(NULL);

        // Calculate time remaining for current state
        timeRemaining = (currentState * (currentTime - startTime)) / 1000;

        // Change state if time is up
        if(timeRemaining == 0) {
            currentState = (currentState + 1) % 3;
            startTime = currentTime;
        }

        // Print current state and time remaining
        printf("Current state: ");
        switch(currentState) {
            case 0:
                printf("Green\n");
                break;
            case 1:
                printf("Yellow\n");
                break;
            case 2:
                printf("Red\n");
                break;
        }
        printf("Time remaining: %d seconds\n", timeRemaining);

        // Wait for remaining time
        sleep(timeRemaining);
    }

    return 0;
}