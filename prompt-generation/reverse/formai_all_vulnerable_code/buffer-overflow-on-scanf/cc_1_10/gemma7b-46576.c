//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define FLOOR_NUM 10

int main()
{
    int currentFloor = 1, targetFloor;
    char direction;

    printf("Current floor: %d\n", currentFloor);

    // Get target floor and direction
    printf("Enter target floor: ");
    scanf("%d", &targetFloor);

    printf("Enter direction (U/D): ");
    scanf(" %c", &direction);

    // Validate input
    if (targetFloor < 1 || targetFloor > FLOOR_NUM)
    {
        printf("Invalid target floor.\n");
        return 1;
    }

    // Calculate direction and distance
    int distance = abs(currentFloor - targetFloor);
    char directionChar = direction == 'U' ? 'Up' : 'Down';

    // Simulate elevator movement
    for (int i = 0; i < distance; i++)
    {
        currentFloor++;
        if (direction == 'U')
        {
            printf("Elevator moving %s to floor %d...\n", directionChar, currentFloor);
        }
        else
        {
            printf("Elevator moving %s to floor %d...\n", directionChar, currentFloor);
        }
    }

    // Reach target floor
    if (currentFloor == targetFloor)
    {
        printf("Reached target floor! Door opening...\n");
    }

    return 0;
}