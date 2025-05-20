//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_FLOOR 10

int main()
{
    int currentFloor = 0;
    int destFloor = 0;
    char direction = 's'; // 's' for still, 'u' for up, 'd' for down
    bool isMoving = false;
    bool isValid = false;

    printf("Welcome to Brave Elevator Simulator!\n\n");

    while (true)
    {
        printf("Current Floor: %d\n", currentFloor);
        printf("Destined Floor: %d\n", destFloor);
        printf("Elevator direction: %c\n", direction);
        printf("Elevator status: %s\n\n", isMoving ? "moving" : "stationary");

        if (!isValid)
        {
            printf("Enter desired floor (1-%d): ", MAX_FLOOR);
            scanf("%d", &destFloor);

            if (destFloor < 1 || destFloor > MAX_FLOOR)
            {
                printf("Invalid floor entered. Please enter a number between 1 and %d.\n\n", MAX_FLOOR);
                continue;
            }

            isValid = true;
            direction = destFloor > currentFloor ? 'u' : 'd';
            isMoving = true;
        }

        if (isMoving)
        {
            printf("Moving...\n");

            if (direction == 'u')
            {
                currentFloor++;

                if (currentFloor >= destFloor)
                {
                    printf("You have arrived at your destination, floor %d.\n\n", destFloor);
                    isMoving = false;
                    isValid = false;
                }
            }
            else if (direction == 'd')
            {
                currentFloor--;

                if (currentFloor <= destFloor)
                {
                    printf("You have arrived at your destination, floor %d.\n\n", destFloor);
                    isMoving = false;
                    isValid = false;
                }
            }
        }
        else
        {
            printf("The elevator is currently stationary.\n\n");
        }
    }

    return 0;
}