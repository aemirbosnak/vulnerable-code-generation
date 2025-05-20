//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: real-life
#include <stdio.h>
#define MAX_FLOORS 20

/* Function to move the elevator */
void moveElevator(int currentFloor, int targetFloor);

/* Function to display elevator status */
void displayStatus(int currentFloor, int targetFloor);

int main()
{
    int currentFloor = 1; // the initial floor
    int targetFloor;
    char choice;

    printf("\n*** Welcome to the Elevator Simulation ***\n\n");

    do
    {
        printf("\nEnter the floor number you want to go to (1-%d): ", MAX_FLOORS);
        scanf("%d", &targetFloor);

        if (targetFloor < 1 || targetFloor > MAX_FLOORS)
        {
            printf("\nInvalid floor number. Please try again.\n");
        }
        else if (targetFloor == currentFloor)
        {
            printf("\nYou are already on floor %d.\n", currentFloor);
        }
        else
        {
            moveElevator(currentFloor, targetFloor);
            displayStatus(currentFloor, targetFloor);
            currentFloor = targetFloor;
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThe elevator simulation has ended.\n");

    return 0;
}

/* Function to move the elevator */
void moveElevator(int currentFloor, int targetFloor)
{
    printf("\nElevator is moving from floor %d to floor %d...\n", currentFloor, targetFloor);
}

/* Function to display elevator status */
void displayStatus(int currentFloor, int targetFloor)
{
    printf("\nElevator has arrived at floor %d.\nYou have reached your destination at floor %d.\n", targetFloor, targetFloor);
}