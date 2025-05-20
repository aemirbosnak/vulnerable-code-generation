//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor;
    int currentFloor = 1;
    char direction;

    // Create a loop to simulate the elevator movement
    while (1)
    {
        // Get the floor number and direction from the user
        printf("Enter the floor number (up/down): ");
        scanf("%c %d", &direction, &floor);

        // Check if the direction is valid
        if (direction != 'u' && direction != 'd')
        {
            printf("Invalid direction.\n");
            continue;
        }

        // Check if the floor number is within the building limits
        if (floor < 1 || floor > 10)
        {
            printf("Invalid floor number.\n");
            continue;
        }

        // Update the current floor
        currentFloor = floor;

        // Simulate the elevator movement
        printf("The elevator is moving... \n");
        for (int i = 0; i < floor - currentFloor; i++)
        {
            printf("Floor %d is passing by.\n", currentFloor + i);
            currentFloor++;
        }

        // Announce the arrival at the destination floor
        printf("The elevator has arrived at floor %d.\n", currentFloor);

        // Check if the user wants to continue
        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        // Break out of the loop if the user does not want to continue
        if (answer != 'Y')
        {
            break;
        }
    }

    return 0;
}