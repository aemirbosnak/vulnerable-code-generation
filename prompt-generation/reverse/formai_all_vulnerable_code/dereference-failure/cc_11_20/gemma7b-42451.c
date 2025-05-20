//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define the elevator floor numbers
    int floor_num = 10;

    // Create an array to store the elevator passengers
    char **passengers = (char **)malloc(floor_num * sizeof(char *));
    for (int i = 0; i < floor_num; i++)
    {
        passengers[i] = (char *)malloc(20 * sizeof(char));
    }

    // Initialize the elevator position
    int current_floor = 1;

    // Simulate the elevator movement
    while (1)
    {
        // Get the destination floor from the user
        int destination_floor = 0;
        printf("Enter your destination floor: ");
        scanf("%d", &destination_floor);

        // Check if the destination floor is valid
        if (destination_floor < 1 || destination_floor > floor_num)
        {
            printf("Invalid destination floor.\n");
            continue;
        }

        // Calculate the direction of travel
        int direction = 0;
        if (destination_floor > current_floor)
        {
            direction = 1;
        }
        else if (destination_floor < current_floor)
        {
            direction = -1;
        }

        // Move the elevator to the destination floor
        for (int i = 0; i < direction; i++)
        {
            current_floor++;
            printf("The elevator is moving to floor %d.\n", current_floor);
            sleep(1);
        }

        // Print the destination floor
        printf("The elevator has reached floor %d.\n", destination_floor);

        // Check if the elevator is empty
        int is_empty = 1;
        for (int i = 0; i < floor_num; i++)
        {
            if (passengers[i][0] != '\0')
            {
                is_empty = 0;
            }
        }

        // If the elevator is empty, end the simulation
        if (is_empty)
        {
            printf("The elevator is now empty.\n");
            break;
        }
    }

    // Free the memory allocated for the passengers and elevator position
    for (int i = 0; i < floor_num; i++)
    {
        free(passengers[i]);
    }
    free(passengers);

    return 0;
}