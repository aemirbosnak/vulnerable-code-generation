//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: rigorous
#include <stdio.h>

int main()
{
    // Initialize variables
    int floor = 0;
    int currentFloor = 0;
    int nextFloor = 0;
    int currentPassengers = 0;
    int nextPassengers = 0;
    
    // Main loop
    while (1)
    {
        // Prompt user for floor
        printf("Current floor: %d\n", currentFloor);
        printf("Enter the floor you want to go to: ");
        scanf("%d", &nextFloor);
        
        // Check if next floor is within range
        if (nextFloor < 0 || nextFloor > 100)
        {
            printf("Invalid floor number. Please try again.\n");
            continue;
        }
        
        // Calculate next floor
        nextFloor = currentFloor + (nextFloor - currentFloor);
        
        // Check if next floor is already occupied
        if (nextFloor == currentFloor)
        {
            printf("Elevator is already on this floor.\n");
            continue;
        }
        
        // Check if next floor is busy
        if (nextFloor > currentFloor)
        {
            printf("Floor %d is busy. Please wait.\n", nextFloor);
            currentPassengers = 1;
            currentFloor = nextFloor;
        }
        
        // Check if next floor is empty
        else if (nextFloor < currentFloor)
        {
            printf("Floor %d is empty. Please enter.\n", nextFloor);
            currentPassengers = 0;
            currentFloor = nextFloor;
        }
        
        // Move elevator to next floor
        printf("Moving to floor %d...\n", nextFloor);
        printf("Current floor: %d\n", currentFloor);
        printf("Current passengers: %d\n", currentPassengers);
        printf("Next floor: %d\n", nextFloor);
        printf("Next passengers: %d\n", nextPassengers);
        printf("\n");
    }
}