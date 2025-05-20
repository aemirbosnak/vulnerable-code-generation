//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Sherlock Holmes
#include<stdio.h>

int main()
{
    int floor_num, curr_floor=1, dir=1, dest_floor;
    printf("Welcome to the Baker Street Tower elevator!\n");

    while(1)
    {
        printf("\nYou are on floor %d\n", curr_floor);
        printf("Enter the floor number you want to go to: ");
        scanf("%d",&dest_floor);
        
        // check if the entered floor is valid
        if(dest_floor<=0 || dest_floor>10)
        {
            printf("\nInvalid floor number entered. Please enter a floor number between 1 and 10.\n");
            continue;
        }

        // check if elevator is already at dest_floor
        if(curr_floor == dest_floor)
        {
            printf("\nYou are already on floor %d.\n",curr_floor);
            continue;
        }

        // check direction of elevator
        if(dest_floor > curr_floor)
        {
            printf("\nGoing up...\n");
            dir = 1;
        }
        else
        {
            printf("\nGoing down...\n");
            dir = -1;
        }

        // simulate elevator movement
        while(curr_floor != dest_floor)
        {
            printf("Elevator at floor %d\n", curr_floor);
            curr_floor += dir;
        }

        // elevator has reached destination
        printf("\nYou have arrived at floor %d\n", curr_floor);
    }
    return 0;
}