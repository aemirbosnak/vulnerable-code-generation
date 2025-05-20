//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor, currentFloor = 1, direction = 0, passengers = 0;
    char directionStr[] = "UP";

    // Display welcome message
    printf("Welcome to the vintage elevator simulator!\n");

    // Loop until the user chooses to exit
    while (1)
    {
        // Get the user's desired floor
        printf("Enter your desired floor (1-10): ");
        scanf("%d", &floor);

        // Check if the user wants to go up or down
        printf("Enter 'up' or 'down': ");
        scanf(" %s", directionStr);

        // Validate the input
        if (floor < 1 || floor > 10)
        {
            printf("Invalid floor number.\n");
            continue;
        }

        // Determine the direction
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
            printf("Invalid input.\n");
            continue;
        }

        // Calculate the number of passengers
        passengers = rand() % 5;

        // Simulate elevator movement
        currentFloor += direction * passengers;

        // Display the current floor
        printf("Current floor: %d\n", currentFloor);

        // Check if the user wants to exit
        printf("Do you want to exit? (Y/N): ");
        char exitStr[1];
        scanf(" %c", exitStr);

        // Exit if the user enters Y
        if (exitStr[0] == 'Y' || exitStr[0] == 'y')
        {
            break;
        }
    }

    // Thank the user
    printf("Thank you for using the vintage elevator simulator!\n");

    return 0;
}