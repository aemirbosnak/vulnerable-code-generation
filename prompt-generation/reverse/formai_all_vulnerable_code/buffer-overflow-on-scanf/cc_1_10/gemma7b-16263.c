//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int floor;
    char direction;
    int currentFloor = 0;

    // The post-apocalyptic city is a vertical one, with floors numbered from 0 to 10
    int numFloors = 11;

    // The elevator is on the first floor, facing east
    currentFloor = 0;
    direction = 'E';

    // Get the floor number and direction from the user
    printf("Enter the floor number (1-10): ");
    scanf("%d", &floor);

    // Check if the floor is within the range
    if (floor < 1 || floor > numFloors)
    {
        printf("Invalid floor number.\n");
    }
    else
    {
        // Calculate the direction of travel
        if (floor > currentFloor)
        {
            direction = 'N';
        }
        else
        {
            direction = 'S';
        }

        // Move the elevator to the specified floor
        for (int i = 0; i < floor - currentFloor; i++)
        {
            printf("The elevator is moving %c.\n", direction);
            currentFloor++;
        }

        // The elevator has reached the specified floor
        printf("The elevator has reached floor %d.\n", floor);
    }

    return;
}