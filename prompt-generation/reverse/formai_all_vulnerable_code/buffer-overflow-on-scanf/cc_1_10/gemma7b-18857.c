//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor, currentFloor = 1, direction = 0, flag = 0;
    char input;

    // Define the number of floors
    int numFloors = 10;

    // Create a loop to simulate the elevator movement
    while (flag == 0)
    {
        // Display the current floor
        printf("Current floor: %d\n", currentFloor);

        // Get the user input
        printf("Enter direction (up/down): ");
        scanf("%c", &input);

        // Check if the user input is valid
        if (input != 'u' && input != 'd')
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Determine the direction of travel
        if (input == 'u')
        {
            direction = 1;
        }
        else if (input == 'd')
        {
            direction = -1;
        }

        // Move the elevator to the next floor
        currentFloor += direction;

        // Check if the elevator has reached the desired floor
        if (currentFloor == floor)
        {
            flag = 1;
            printf("Destination reached.\n");
        }
    }

    return 0;
}