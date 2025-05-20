//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int floors, numElevators;
    printf("Enter number of floors in building: ");
    scanf("%d", &floors);
    printf("Enter number of elevators: ");
    scanf("%d", &numElevators);

    // Creating array of floors to store their status (1 for Requested, 0 for None)
    int floorStatus[floors];
    for(int i=0; i<floors; i++)
    {
        floorStatus[i] = 0; 
    }

    //Creating array of elevators to store their status (1 for Occupied, 0 for Available)
    int elevatorStatus[numElevators];
    for(int i=0; i<numElevators; i++)
    {
        elevatorStatus[i] = 0; 
    }

    //Starting Elevator Managment Loop
    int currentFloor, currentElevator, userInput;
    bool floorFound, elevatorFound;
    do
    {
        printf("\nWhich floor do you want to go to?: ");
        scanf("%d", &userInput);

        //Searching for the floor
        floorFound = false;
        for(int i=0; i<floors; i++)
        {
            if(i+1 == userInput && floorStatus[i] == 0)
            {
                floorFound = true;
                floorStatus[i] = 1;
                currentFloor = i+1;
                printf("\nFloor %d is requested, wait for elevator\n", currentFloor);
                break;
            }
        }
        if(floorFound == false)
        {
            printf("\nFloor %d is unavailble or already requested, please try another floor\n", userInput);
            continue;
        }

        //Searching for available elevator at lowest floor
        printf("\nChecking for available elevator...\n");
        elevatorFound = false;
        for(int i=0; i<numElevators; i++)
        {
            if(elevatorStatus[i] == 0)
            {
                currentElevator = i+1;
                elevatorFound = true;
                break;
            }
        }

        //If no available elevators found, Set the Elevator at highest preferred floor to be unoccupied and request the Elevator at the user preferred floor
        if(elevatorFound == false)
        {
            printf("\nSorry, no available elevators at this time. Please wait until elevator(s) are unoccupied\n");
            int highestPreferredFloor = 0;
            for(int i=0; i<numElevators; i++)
            {
                if(elevatorStatus[i] == 1 && currentFloor > highestPreferredFloor)
                {
                    highestPreferredFloor = currentFloor;
                }
            }
            printf("\nThe current elevator at the highest preferred floor has been set to unoccupied\n");
            for(int i=0; i<numElevators; i++)
            {
                if(elevatorStatus[i] == 1 && currentFloor == highestPreferredFloor)
                {
                    elevatorStatus[i] = 0;
                    printf("\nThe elevator at floor %d is now unoccupied\n", highestPreferredFloor);
                    currentElevator = i+1;
                    elevatorFound = true;
                    break;
                }
            }
        }
        if(elevatorFound == true)
        {
            elevatorStatus[currentElevator-1] = 1;
            printf("\nElevator %d has arrived at floor %d\n", currentElevator, currentFloor);
            floorStatus[currentFloor-1] = 0;
            printf("\nElevator %d is now on the way to floor %d\n", currentElevator, userInput);
            printf("\nElevator %d has arrived at floor %d\n", currentElevator, userInput);
            elevatorStatus[currentElevator-1] = 0;
        }
    }while(userInput != 0);

    printf("\nExiting Program...\n");
    return 0;
}