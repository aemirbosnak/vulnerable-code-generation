//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor, currentFloor = 1, passengers = 0;
    char direction;

    // Define the floor buttons
    int floorButtons[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Display the current floor
    printf("Current floor: %d\n", currentFloor);

    // Get the direction of travel
    printf("Enter direction (U/D): ");
    scanf("%c", &direction);

    // Check if the direction is valid
    if (direction != 'U' && direction != 'D')
    {
        printf("Invalid direction.\n");
        return 1;
    }

    // Loop until the elevator reaches the desired floor
    while (currentFloor != floor)
    {
        // Increment or decrement the current floor
        if (direction == 'U')
        {
            currentFloor++;
        }
        else if (direction == 'D')
        {
            currentFloor--;
        }

        // Check if the floor button is pressed
        if (floorButtons[currentFloor] == 1)
        {
            // Stop the elevator
            printf("Floor reached: %d\n", currentFloor);
            currentFloor = floor;
            passengers++;
        }

        // Display the current floor
        printf("Current floor: %d\n", currentFloor);
    }

    // Display the number of passengers
    printf("Number of passengers: %d\n", passengers);

    return 0;
}