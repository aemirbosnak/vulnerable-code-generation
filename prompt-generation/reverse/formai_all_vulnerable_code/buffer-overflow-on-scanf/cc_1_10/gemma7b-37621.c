//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor_num;
    char direction;

    // Initialize the elevator position
    int current_floor = 1;

    // Loop until the user enters a valid floor number
    while (1)
    {
        printf("Enter the floor number: ");
        scanf("%d", &floor_num);

        // Check if the floor number is within the range
        if (floor_num < 1 || floor_num > 10)
        {
            printf("Invalid floor number.\n");
        }
        else
        {
            break;
        }
    }

    // Get the direction of travel
    printf("Enter the direction (up/down): ");
    scanf(" %c", &direction);

    // Move the elevator to the specified floor
    switch (direction)
    {
        case 'u':
            current_floor++;
            break;
        case 'd':
            current_floor--;
            break;
        default:
            printf("Invalid direction.\n");
    }

    // Display the elevator's current floor
    printf("The elevator is currently on floor %d.\n", current_floor);

    return 0;
}