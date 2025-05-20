//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int currentFloor = 1, targetFloor, numPassengers = 0, elevatorStatus = 0;
    char direction = ' ';

    // Create a timer to simulate the elevator movement
    time_t timerStart, timerEnd;
    double timeTaken;

    // Initialize the elevator movement timer
    timerStart = time(NULL);

    // Get the target floor from the user
    printf("Enter the target floor: ");
    scanf("%d", &targetFloor);

    // Calculate the direction of the elevator movement
    if (targetFloor > currentFloor)
    {
        direction = 'up';
    }
    else
    {
        direction = 'down';
    }

    // Simulate the elevator movement
    while (currentFloor != targetFloor)
    {
        // Increment or decrement the current floor
        currentFloor += direction == 'up' ? 1 : -1;

        // Update the elevator status
        elevatorStatus = 1;

        // Sleep for a random amount of time
        timeTaken = rand() % 5 + 1;
        sleep(timeTaken);

        // Update the time taken
        timeTaken = time(NULL) - timerStart;

        // Print the current floor
        printf("Current floor: %d\n", currentFloor);

        // Print the time taken
        printf("Time taken: %.2f seconds\n", timeTaken);

        // Clear the elevator status
        elevatorStatus = 0;
    }

    // Print the final floor
    printf("Target floor reached: %d\n", targetFloor);

    // End the timer
    timerEnd = time(NULL);

    // Calculate the total time taken
    timeTaken = timerEnd - timerStart;

    // Print the total time taken
    printf("Total time taken: %.2f seconds\n", timeTaken);

    // Exit the program
    exit(0);
}