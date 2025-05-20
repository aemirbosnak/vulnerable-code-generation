//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int floors = 10;
    int current_floor = 1;
    int direction = 0; // 0 for stationary, 1 for up, 2 for down
    int dest_floor = 0;

    printf("Welcome to Elevator Simulation in C\n\n");

    while(1)
    {
        printf("Current floor: %d\n", current_floor);
        printf("\nPlease enter the destination floor (1 - 10) or 0 to exit: ");
        scanf("%d", &dest_floor);

        if(dest_floor == 0)
        {
            printf("\nThank you for using Elevator Simulation!\n");
            exit(0);
        }
        else if(dest_floor > floors || dest_floor < 1)
        {
            printf("\nInvalid floor. Please try again.\n");
            continue;
        }
        else if(dest_floor == current_floor)
        {
            printf("\nYou are already on this floor. Please choose another floor.\n");
            continue;
        }
        else if(dest_floor > current_floor)
        {
            direction = 1;
            printf("\nGoing up...\n");
        }
        else
        {
            direction = 2;
            printf("\nGoing down...\n");
        }

        while(current_floor != dest_floor)
        {
            if(direction == 1)
            {
                current_floor++;
            }
            else
            {
                current_floor--;
            }

            printf("Current floor: %d\n", current_floor);
            sleep(1);
        }

        printf("\nYou have arrived at floor %d. Thank you for using our elevator!\n", current_floor);
    }

    return 0;
}