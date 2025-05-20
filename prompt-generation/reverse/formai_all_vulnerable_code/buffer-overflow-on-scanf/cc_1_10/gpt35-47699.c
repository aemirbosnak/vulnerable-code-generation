//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Traffic Light states
enum State {
    RED,
    YELLOW,
    GREEN
};

// Function prototypes
void runController(int [], float);
enum State getNextState(enum State);

// Main function
int main() {
    int timings[3];
    float duration;

    // Get user input for timings and duration
    printf("Enter timings for red, yellow and green lights (in seconds): ");
    scanf("%d %d %d", &timings[0], &timings[1], &timings[2]);
    printf("Enter the duration for which to run the controller (in minutes): ");
    scanf("%f", &duration);

    // Convert duration to seconds
    duration *= 60;

    // Run the controller
    runController(timings, duration);

    return 0;
}

// Function to run the traffic light controller
void runController(int timings[], float duration) {
    // Initialize state as red
    enum State currentState = RED;
    // Set the start time
    time_t startTime = time(NULL);
    // Initialize the elapsed time as 0
    float elapsedTime = 0;

    while (elapsedTime < duration) {
        // Print the current state
        printf("Current state: ");
        switch (currentState) {
            case RED:
                printf("Red\n");
                break;
            case YELLOW:
                printf("Yellow\n");
                break;
            case GREEN:
                printf("Green\n");
                break;
        }

        // Sleep for the appropriate time
        switch (currentState) {
            case RED:
                sleep(timings[0]);
                break;
            case YELLOW:
                sleep(timings[1]);
                break;
            case GREEN:
                sleep(timings[2]);
                break;
        }

        // Get the next state
        currentState = getNextState(currentState);

        // Update the elapsed time
        elapsedTime = difftime(time(NULL), startTime);
    }
}

// Function to calculate the next state
enum State getNextState(enum State currentState) {
    // Randomly decide whether to switch or not
    bool shouldSwitch = rand() % 2;

    // Determine the next state
    switch (currentState) {
        case RED:
            if (shouldSwitch) {
                return GREEN;
            } else {
                return YELLOW;
            }
            break;
        case YELLOW:
            return RED;
            break;
        case GREEN:
            if (shouldSwitch) {
                return YELLOW;
            } else {
                return RED;
            }
            break;
    }
}