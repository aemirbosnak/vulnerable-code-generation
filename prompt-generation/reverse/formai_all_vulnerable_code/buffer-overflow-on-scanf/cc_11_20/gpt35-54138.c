//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_FLOORS 10
#define MIN_FLOORS 2
#define MAX_PASSENGERS 10
#define MAX_CAPACITY 1000

int currentFloor = 1;
int destinationFloor;
int numPassengers = 0;
int totalWeight = 0;
int destinations[MAX_FLOORS];
int numDestinations = 0;
bool doorsOpen = false;

void printStatus()
{
    printf("\nCurrent Floor: %d\n", currentFloor);
    printf("Number of Passengers: %d\n", numPassengers);
    printf("Total Weight: %d\n", totalWeight);
    printf("Destinations: ");

    for (int i = 0; i < numDestinations; i++)
    {
        printf("%d ", destinations[i]);
    }
    printf("\n\n");
}

int main()
{
    int numFloors;
    int maxCapacity;
    int passengerWeight;

    printf("Welcome to Elevator Simulator! Let's set up the elevator.\n\n");

    do {
        printf("How many floors are in the building (between %d and %d)? ", MIN_FLOORS, MAX_FLOORS);
        scanf("%d", &numFloors);
    } while (numFloors < MIN_FLOORS || numFloors > MAX_FLOORS);

    do {
        printf("What is the maximum capacity of the elevator (between 1 and %d)? ", MAX_CAPACITY);
        scanf("%d", &maxCapacity);
    } while (maxCapacity < 1 || maxCapacity > MAX_CAPACITY);

    printf("What is the weight of a single passenger? ");
    scanf("%d", &passengerWeight);

    printf("\nAll set up! Let's get this elevator moving.\n\n");

    while (true)
    {
        printStatus();

        if (doorsOpen)
        {
            printf("Type 'c' to close the doors: ");
            char input;
            scanf(" %c", &input);

            if (tolower(input) == 'c')
            {
                doorsOpen = false;
                printf("Doors closed.\n");
            }
            else
            {
                printf("Invalid input. Try again.\n");
            }
        }
        else
        {
            printf("Type 'o' to open the doors or 'd' to set a new destination: ");
            char input;
            scanf(" %c", &input);

            if (tolower(input) == 'o')
            {
                doorsOpen = true;
                printf("Doors opened.\n");

                for (int i = 0; i < numDestinations; i++)
                {
                    if (destinations[i] == currentFloor)
                    {
                        numPassengers--;
                        totalWeight -= passengerWeight;
                        destinations[i] = destinations[numDestinations - 1];
                        numDestinations--;
                    }
                }
            }
            else if (tolower(input) == 'd')
            {
                printf("Which floor do you want to go to (between 1 and %d)? ", numFloors);
                scanf("%d", &destinationFloor);

                if (destinationFloor < 1 || destinationFloor > numFloors || destinationFloor == currentFloor)
                {
                    printf("Invalid destination. Try again.\n");
                }
                else if (numPassengers == maxCapacity)
                {
                    printf("Elevator is at full capacity. Wait for the next one.\n");
                }
                else
                {
                    destinations[numDestinations] = destinationFloor;
                    numDestinations++;
                    printf("Destination set to floor %d.\n", destinationFloor);
                }
            }
            else
            {
                printf("Invalid input. Try again.\n");
            }
        }

        if (numDestinations == 0)
        {
            printf("No destinations set. Elevator will stay on current floor.\n");
        }
        else if (destinations[0] > currentFloor)
        {
            printf("Moving up to floor %d.\n", destinations[0]);
            currentFloor++;
        }
        else if (destinations[0] < currentFloor)
        {
            printf("Moving down to floor %d.\n", destinations[0]);
            currentFloor--;
        }
        else
        {
            printf("Arrived at floor %d.\n", destinations[0]);
            for (int i = 0; i < numDestinations; i++)
            {
                if (destinations[i] == currentFloor)
                {
                    numPassengers--;
                    totalWeight -= passengerWeight;
                    destinations[i] = destinations[numDestinations - 1];
                    numDestinations--;
                }
            }
        }

        if (totalWeight > maxCapacity)
        {
            printf("Overweight capacity. Elevator will not move.\n");
            currentFloor--;
            doorsOpen = true;
            numDestinations = 0;
            numPassengers = 0;
            totalWeight = 0;
            printf("Doors opened.\n");
        }

        if (currentFloor == numFloors)
        {
            printf("Top floor reached. Going back down.\n");
            destinations[0] = 1;
        }
        else if (currentFloor == 1)
        {
            printf("Bottom floor reached. Going back up.\n");
            destinations[0] = numFloors;
        }

        if (numPassengers == 0 && numDestinations == 0)
        {
            printf("Elevator is empty. Start again.\n");
            break;
        }
    }

    return 0;
}