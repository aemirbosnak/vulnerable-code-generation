//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int floor, currentFloor = 1, direction, passengers = 0;
    char directionStr[20];

    // Display the current floor
    printf("Current floor: %d", currentFloor);

    // Get the direction of travel
    printf("\nEnter direction (up/down): ");
    scanf("%s", directionStr);

    // Convert the direction into an integer
    if (strcmp(directionStr, "up") == 0)
    {
        direction = 1;
    }
    else if (strcmp(directionStr, "down") == 0)
    {
        direction = -1;
    }
    else
    {
        printf("Invalid direction");
        return;
    }

    // Simulate the elevator movement
    for (floor = currentFloor; direction * floor < 0 || floor <= 10; floor++)
    {
        currentFloor += direction;

        // Check if the floor is a stop
        if (currentFloor % 3 == 0)
        {
            passengers++;
            printf("Floor %d: Doors open\n", currentFloor);
        }

        // Update the direction string
        if (direction > 0)
        {
            strcpy(directionStr, "up");
        }
        else
        {
            strcpy(directionStr, "down");
        }

        // Display the current floor and passengers
        printf("Current floor: %d", currentFloor);
        printf(", Passengers: %d", passengers);
        printf("\n");
    }

    // Display the final floor and passengers
    printf("Final floor: %d", currentFloor);
    printf(", Passengers: %d", passengers);
    printf("\n");

    // Thank the user
    printf("Thank you for riding the elevator!");

    return;
}