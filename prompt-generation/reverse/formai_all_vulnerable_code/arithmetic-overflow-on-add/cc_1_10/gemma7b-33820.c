//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a structure to represent the elevator
    typedef struct Elevator
    {
        int currentFloor;
        int destinationFloor;
        int passengers;
    } Elevator;

    // Create an array of elevators
    Elevator elevators[5] = {
        {1, 5, 0},
        {2, 3, 1},
        {3, 4, 2},
        {4, 2, 3},
        {5, 1, 4}
    };

    // Simulate the elevator movement
    for (int i = 0; i < 100; i++)
    {
        // Randomly select a destination floor
        elevators[i].destinationFloor = rand() % 5 + 1;

        // Move the elevator to the destination floor
        while (elevators[i].currentFloor != elevators[i].destinationFloor)
        {
            // Increment the current floor
            elevators[i].currentFloor++;

            // Print the elevator's current floor
            printf("Elevator %d is on floor %d.\n", elevators[i].currentFloor);

            // Sleep for a random amount of time
            sleep(rand() % 2);
        }

        // Print the elevator's destination floor
        printf("Elevator %d has reached floor %d.\n", elevators[i].currentFloor, elevators[i].destinationFloor);

        // Reset the elevator's passengers
        elevators[i].passengers = 0;
    }

    return 0;
}