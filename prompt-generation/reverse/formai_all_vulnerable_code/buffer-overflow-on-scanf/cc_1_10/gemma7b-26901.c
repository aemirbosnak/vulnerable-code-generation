//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int floor, currentFloor = 1, direction = 0, timer = 0;
    char directionStr[2] = "";

    // Initialize the random number generator
    srand(time(NULL));

    // Loop until the user enters a floor number
    printf("Enter the floor number: ");
    scanf("%d", &floor);

    // Calculate the direction of travel
    if (floor > currentFloor)
    {
        direction = 1;
        directionStr[0] = 'U';
    }
    else if (floor < currentFloor)
    {
        direction = -1;
        directionStr[0] = 'D';
    }

    // Start the timer
    timer = 0;

    // Simulate the elevator movement
    while (currentFloor != floor)
    {
        // Print the current floor
        printf("Current floor: %d\n", currentFloor);

        // Randomly pause for 1-3 seconds
        sleep(rand() % 3 + 1);

        // Move the elevator one floor
        currentFloor += direction;

        // Increment the timer
        timer++;

        // Print the direction of travel
        printf("Direction: %s\n", directionStr);
    }

    // Print the final floor
    printf("Final floor: %d\n", currentFloor);

    // Print the time taken
    printf("Time taken: %d seconds\n", timer);

    return;
}