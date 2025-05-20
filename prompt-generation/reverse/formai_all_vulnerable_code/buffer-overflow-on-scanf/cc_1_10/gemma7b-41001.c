//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the elevator floor numbers
    int floors = 5;

    // Create a variable to store the current floor
    int currentFloor = 1;

    // Create a loop to simulate the elevator moving
    while (1)
    {
        // Print the current floor
        printf("You are currently on floor %d.\n", currentFloor);

        // Get the desired floor from the user
        int desiredFloor = 0;
        printf("Enter the desired floor: ");
        scanf("%d", &desiredFloor);

        // Check if the desired floor is valid
        if (desiredFloor < 1 || desiredFloor > floors)
        {
            printf("Invalid floor number.\n");
            continue;
        }

        // Calculate the direction of travel
        int direction = 0;
        if (desiredFloor > currentFloor)
        {
            direction = 1;
        }
        else
        {
            direction = -1;
        }

        // Simulate the elevator moving
        for (int i = 0; i < 10; i++)
        {
            // Print the elevator moving
            printf("The elevator is moving...\n");

            // Update the current floor
            currentFloor += direction;

            // Pause for a second
            sleep(1);
        }

        // Print the arrival at the desired floor
        printf("The elevator has arrived at floor %d.\n", desiredFloor);

        // Check if the user wants to continue
        int continueFlag = 0;
        printf("Do you want to continue? (y/n): ");
        scanf("%c", &continueFlag);

        // If the user wants to continue, start the loop again
        if (continueFlag == 'y')
        {
            continue;
        }

        // Exit the program
        break;
    }

    return 0;
}