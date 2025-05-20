//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOOR 10

typedef struct Elevator
{
    int currentFloor;
    int targetFloor;
    int passengers;
    int direction;
} Elevator;

Elevator elevator;

void moveElevator()
{
    int floor;

    // Check if the elevator is moving
    if (elevator.direction)
    {
        // Increment or decrement the current floor
        elevator.currentFloor += elevator.direction;

        // Check if the elevator has reached the target floor
        if (elevator.currentFloor == elevator.targetFloor)
        {
            elevator.direction = 0;
            printf("Elevator reached target floor.\n");
        }
    }

    // Get the floor number from the user
    printf("Enter the target floor: ");
    scanf("%d", &floor);

    // Set the target floor
    elevator.targetFloor = floor;

    // Check if the elevator is already moving
    if (!elevator.direction)
    {
        // Calculate the direction of movement
        if (elevator.currentFloor < elevator.targetFloor)
        {
            elevator.direction = 1;
            printf("Elevator moving up.\n");
        }
        else if (elevator.currentFloor > elevator.targetFloor)
        {
            elevator.direction = -1;
            printf("Elevator moving down.\n");
        }

        // Start the elevator moving
        elevator.direction = 1;
    }
}

int main()
{
    // Initialize the elevator
    elevator.currentFloor = 1;
    elevator.targetFloor = 0;
    elevator.passengers = 0;
    elevator.direction = 0;

    // Move the elevator
    moveElevator();

    return 0;
}