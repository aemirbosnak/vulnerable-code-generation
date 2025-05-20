//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the elevator floor numbers
    int floor_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Create an array to store the current floor number
    int current_floor = 1;

    // Create a loop to simulate the elevator moving
    while (1)
    {
        // Print the current floor number
        printf("Current floor: %d\n", current_floor);

        // Get the desired floor number from the user
        int desired_floor = 0;
        printf("Enter the desired floor number: ");
        scanf("%d", &desired_floor);

        // Check if the desired floor is within the range
        if (desired_floor < floor_numbers[0] || desired_floor > floor_numbers[9])
        {
            printf("Invalid floor number.\n");
            continue;
        }

        // Calculate the direction of travel
        int direction = 0;
        if (desired_floor > current_floor)
        {
            direction = 1;
        }
        else if (desired_floor < current_floor)
        {
            direction = -1;
        }

        // Simulate the elevator moving to the desired floor
        for (int i = 0; i < 10; i++)
        {
            // Print the elevator moving
            printf("Elevator moving...\n");

            // Update the current floor number
            current_floor += direction;

            // Sleep for a short amount of time
            sleep(1);
        }

        // Print the arrival at the desired floor
        printf("Arriving at floor %d.\n", desired_floor);

        // Ask the user if they want to continue
        char continue_yn = ' ';
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_yn);

        // Break out of the loop if the user does not want to continue
        if (continue_yn == 'N')
        {
            break;
        }
    }

    return 0;
}