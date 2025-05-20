//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include<stdio.h>

int main()
{
    int currentFloor = 1, destinationFloor = 0, elevatorDirection = 0, numberOfFloors = 10;
    int elevatorStatus = 1; // 1 = idle, 2 = moving
    int upRequests[10] = {0}; // Array to store up requests from each floor
    int downRequests[10] = {0}; // Array to store down requests from each floor

    printf("Welcome to the Elevator Simulation Program\n");

    // Simulation loop
    while(1)
    {
        // Check if there are any pending requests
        if((upRequests[currentFloor-1] || downRequests[currentFloor-1]) && elevatorStatus == 1)
        {
            // Elevator is idle, serve the request on current floor
            if(upRequests[currentFloor-1])
            {
                elevatorDirection = 1;
                destinationFloor = currentFloor + 1;
                upRequests[currentFloor-1] = 0;
            }
            else
            {
                elevatorDirection = -1;
                destinationFloor = currentFloor - 1;
                downRequests[currentFloor-1] = 0;
            }
            elevatorStatus = 2;
        }
        else if(elevatorStatus == 2)
        {
            // Elevator is moving, check if it has reached its destination
            if(currentFloor == destinationFloor)
            {
                elevatorStatus = 1;
                printf("Elevator has reached its destination at floor %d\n", currentFloor);
            }
            else
            {
                currentFloor += elevatorDirection;
                printf("Elevator is moving, current floor is %d\n", currentFloor);
            }
        }
        else
        {
            // Elevator is idle, wait for a request
            printf("Elevator is idle, waiting for a request\n");
        }

        // Take user input for floor requests
        printf("Enter floor number (1-10) for up/down request (0 to exit): ");
        int floorRequest, directionRequest;
        scanf("%d", &floorRequest);
        if(floorRequest == 0)
            break;
        if(floorRequest < 1 || floorRequest > 10)
        {
            printf("Invalid floor number entered\n");
            continue;
        }
        printf("Enter 1 for up request or -1 for down request: ");
        scanf("%d", &directionRequest);
        if(directionRequest != 1 && directionRequest != -1)
        {
            printf("Invalid direction entered\n");
            continue;
        }
        if(directionRequest == 1)
            upRequests[floorRequest-1] = 1;
        else
            downRequests[floorRequest-1] = 1;
    }

    printf("Exiting program\n");

    return 0;
}