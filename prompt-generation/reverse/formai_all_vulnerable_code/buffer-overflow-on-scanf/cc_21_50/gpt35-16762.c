//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: active
#include <stdio.h>
#include <stdbool.h>

#define ELEVATOR_CAPACITY 14
#define ELEVATOR_TOTAL_FLOORS 20

int main()
{
    int currentFloor = 1;
    int direction = 1; // 1 for up, -1 for down
    int numPassengers = 0;
    int passengersGoingTo[ELEVATOR_TOTAL_FLOORS] = {0};

    bool doorOpen = false;
    bool isMoving = false;

    printf("Elevator simulation starting...\n");

    while(true)
    {
        // Check if any passengers need to exit on this floor
        if(passengersGoingTo[currentFloor-1] > 0 && doorOpen)
        {
            printf("%d passengers exit on floor %d\n", passengersGoingTo[currentFloor-1], currentFloor);
            numPassengers -= passengersGoingTo[currentFloor-1];
            passengersGoingTo[currentFloor-1] = 0;
        }

        // Check if any passengers need to enter the elevator
        int floorPassengers = 0;
        printf("Enter number of passengers to board at floor %d: ", currentFloor);
        scanf("%d", &floorPassengers);

        if(numPassengers + floorPassengers > ELEVATOR_CAPACITY)
        {
            printf("Elevator is full, cannot board passengers on floor %d\n", currentFloor);
        }
        else if(doorOpen && floorPassengers > 0)
        {
            printf("%d passengers enter elevator on floor %d\n", floorPassengers, currentFloor);
            numPassengers += floorPassengers;
            passengersGoingTo[currentFloor-1 + (direction == 1 ? 1 : -1)] += floorPassengers;
        }

        // Take action based on elevator state
        if(!isMoving && (numPassengers == 0 || (direction == 1 && currentFloor == ELEVATOR_TOTAL_FLOORS) || (direction == -1 && currentFloor == 1)))
        {
            // Elevator is not moving and has no passengers or reached end of the line
            printf("Elevator is idle\n");
        }
        else if(!isMoving && (direction == 1 && currentFloor < ELEVATOR_TOTAL_FLOORS) || (direction == -1 && currentFloor > 1))
        {
            // Elevator is not moving and there are passengers waiting to be picked up or dropped off
            printf("Doors close and elevator starts moving %s\n", direction == 1 ? "up" : "down");
            isMoving = true;
        }
        else if(isMoving && currentFloor == 1)
        {
            // Elevator reached ground floor 
            printf("Elevator reached ground floor\n");
            direction = 1;
            isMoving = false;
        }
        else if(isMoving && currentFloor == ELEVATOR_TOTAL_FLOORS)
        {
            // Elevator reached top floor
            printf("Elevator reached top floor\n");
            direction = -1;
            isMoving = false;
        }
        else if(isMoving)
        {
            // Elevator moving between floors
            printf("Elevator passing floor %d\n", currentFloor);
        }

        // Update elevator state
        if(isMoving)
        {
            currentFloor += direction;
        }
        else if(doorOpen)
        {
            printf("Doors close\n");
            doorOpen = false;
        }
        else if(numPassengers > 0)
        {
            printf("Doors open on floor %d\n", currentFloor);
            doorOpen = true;
        }
    }
    return 0;
}