//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// function to print the current status of the vehicle
void printStatus(int speed, int direction)
{
    printf("Current Vehicle Status: \n");
    printf("- Speed: %d\n", speed);
    printf("- Direction: %d degrees\n", direction);
}

int main()
{
    int speed = 0; // initial speed of the vehicle
    int direction = 0; // initial direction of the vehicle (North)

    printf("Welcome to Remote Control Vehicle Simulation!\n");

    // infinite loop for continuous simulation until stopped by user
    while (1)
    {
        // print current status of the vehicle
        printStatus(speed, direction);

        // get user input for speed and direction changes
        int newSpeed, newDirection;
        printf("Enter new speed (0-100): ");
        scanf("%d", &newSpeed);
        printf("Enter new direction (0-359 degrees): ");
        scanf("%d", &newDirection);

        // validate user input
        if (newSpeed < 0 || newSpeed > 100)
        {
            printf("Invalid speed input. Speed should be between 0-100.\n");
            continue;
        }
        if (newDirection < 0 || newDirection > 359)
        {
            printf("Invalid direction input. Direction should be between 0-359 degrees.\n");
            continue;
        }

        // update speed and direction of the vehicle
        speed = newSpeed;
        direction = newDirection;

        // ask user if they want to continue simulation
        char continueSim;
        printf("Do you want to continue simulation? (y/n)");
        scanf(" %c", &continueSim);

        // if user chooses to stop simulation, break out of the loop
        if (continueSim == 'n' || continueSim == 'N')
            break;
    }

    printf("Simulation stopped. Thank you for using Remote Control Vehicle Simulation!\n");

    return 0;
}