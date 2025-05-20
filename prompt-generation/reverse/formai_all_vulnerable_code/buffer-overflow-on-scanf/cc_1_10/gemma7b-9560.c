//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor, currentFloor = 1, direction = 0, passengers = 0;
    char directionStr[20];

    // Define the maximum number of floors
    const int maxFloors = 10;

    // Create a loop to simulate the elevator movement
    while (currentFloor != floor)
    {
        // Get the floor number from the user
        printf("Enter the floor number: ");
        scanf("%d", &floor);

        // Validate the floor number
        if (floor < 1 || floor > maxFloors)
        {
            printf("Invalid floor number.\n");
            continue;
        }

        // Calculate the direction of travel
        direction = floor - currentFloor;

        // Update the direction string
        if (direction > 0)
        {
            strcpy(directionStr, "Up");
        }
        else
        {
            strcpy(directionStr, "Down");
        }

        // Print the direction of travel
        printf("The elevator is moving in the %s direction.\n", directionStr);

        // Update the current floor
        currentFloor = floor;

        // Increment the passengers
        passengers++;

        // Print the number of passengers
        printf("The number of passengers is: %d.\n", passengers);

        // Pause the simulation
        sleep(2);
    }

    // Print the final destination
    printf("The elevator has reached the target floor.\n");

    return 0;
}