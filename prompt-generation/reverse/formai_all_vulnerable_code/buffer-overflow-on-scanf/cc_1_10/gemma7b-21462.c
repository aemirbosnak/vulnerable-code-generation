//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor;
    char direction;
    int currentFloor = 1;
    int targetFloor;

    // Display welcome message
    printf("Welcome to the elevator simulation!\n");

    // Get the target floor
    printf("Enter the target floor: ");
    scanf("%d", &targetFloor);

    // Calculate the direction of travel
    if (targetFloor > currentFloor)
    {
        direction = 'u';
    }
    else
    {
        direction = 'd';
    }

    // Simulate elevator movement
    for (floor = currentFloor; floor != targetFloor; floor++)
    {
        // Display the current floor
        printf("Current floor: %d\n", floor);

        // Simulate elevator stopping
        sleep(1);

        // Increment or decrement the current floor
        if (direction == 'u')
        {
            currentFloor++;
        }
        else
        {
            currentFloor--;
        }
    }

    // Display the target floor
    printf("Target floor: %d\n", targetFloor);

    // Display farewell message
    printf("Thank you for using the elevator simulation.\n");

    return 0;
}