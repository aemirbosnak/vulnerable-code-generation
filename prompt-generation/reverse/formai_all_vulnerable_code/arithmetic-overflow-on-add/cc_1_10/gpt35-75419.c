//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOOR 10
#define MAX_PEOPLE 5

bool hasPersonInside = false;

// Helper function to wait a certain amount of time
void wait(int seconds)
{
    clock_t endWait;
    endWait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endWait) {}
}

int main()
{
    srand(time(0));
    int currentFloor = 1;
    int destinationFloor = 1;
    bool goingUp = true;
    int peopleInside = 0;
    int peopleWaiting[MAX_FLOOR] = {0};
    printf("Welcome to the Fun Elevator Simulation!\n\n");

    while (true)
    {
        // Check if the elevator is at its limit
        if (currentFloor == MAX_FLOOR)
            goingUp = false;
        else if (currentFloor == 1)
            goingUp = true;

        // Set the elevator's destination floor
        if (!hasPersonInside)
        {
            // Check if anyone is waiting on the current floor
            if (peopleWaiting[currentFloor-1] > 0)
            {
                printf("\n*ding ding* The elevator doors open and %d person(s) get on!\n", peopleWaiting[currentFloor-1]);
                peopleInside += peopleWaiting[currentFloor-1];
                peopleWaiting[currentFloor-1] = 0;
                hasPersonInside = true;
            }
            else if (peopleInside > 0)
            {
                // Set a random floor for the elevator to go to
                destinationFloor = rand() % (MAX_FLOOR - currentFloor + 1) + currentFloor;
                while (destinationFloor == currentFloor)
                    destinationFloor = rand() % (MAX_FLOOR - currentFloor + 1) + currentFloor;
                printf("\nThe elevator is going %s to floor %d!\n", goingUp ? "up" : "down", destinationFloor);
            }
        }
        else
        {
            // Set a random floor for the elevator to go to
            destinationFloor = rand() % MAX_FLOOR + 1;
            while (destinationFloor == currentFloor)
                destinationFloor = rand() % MAX_FLOOR + 1;
            printf("\nThe elevator is going %s to floor %d!\n", currentFloor < destinationFloor ? "up" : "down", destinationFloor);
        }

        // Move the elevator between floors
        while (currentFloor != destinationFloor)
        {
            wait(1);
            printf("Ding! Floor %d\n", currentFloor);
            currentFloor += goingUp ? 1 : -1;
        }

        // Let people out on their destination floor
        if (hasPersonInside && currentFloor == destinationFloor)
        {
            printf("*ding ding* The elevator doors open and %d person(s) get off!\n", peopleInside);
            peopleInside = 0;
            hasPersonInside = false;
        }
        else if (peopleInside == 0)
            printf("\nThe elevator is now empty.\n");

        // Add some people to a random floor
        if (rand() % 2 == 0)
        {
            int newPeople = rand() % MAX_PEOPLE + 1;
            int newFloor = rand() % MAX_FLOOR + 1;
            if (newFloor != currentFloor)
            {
                printf("On floor %d, %d person(s) are now waiting for the elevator!\n", newFloor, newPeople);
                peopleWaiting[newFloor-1] += newPeople;
            }
        }

        // Wait a bit before looping
        wait(2);
    }

    return 0;
}