//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor, current_floor, direction;

    // Define the number of floors
    int num_floors = 10;

    // Initialize the current floor
    current_floor = 1;

    // Loop until the user enters an exit command
    while (1)
    {
        // Get the user's input
        printf("Enter command (up/down/exit): ");
        scanf("%s", &direction);

        // Check if the user wants to exit
        if (direction == "exit")
        {
            break;
        }

        // Check if the user wants to go up or down
        else if (direction == "up")
        {
            // Check if the current floor is the top floor
            if (current_floor == num_floors)
            {
                printf("You are already on the top floor.\n");
            }
            else
            {
                current_floor++;
                printf("You are now on floor %d.\n", current_floor);
            }
        }
        else if (direction == "down")
        {
            // Check if the current floor is the ground floor
            if (current_floor == 1)
            {
                printf("You are already on the ground floor.\n");
            }
            else
            {
                current_floor--;
                printf("You are now on floor %d.\n", current_floor);
            }
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    // Print a goodbye message
    printf("Thank you for riding the elevator.\n");

    return 0;
}