//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int x = 0, y = 0; //initial position of the vehicle
    printf("Welcome to Remote control Vehicle Simulation\n");
    printf("Enter the number of steps to move the vehicle: ");
    int steps;
    scanf("%d", &steps);

    srand(time(0)); //generating random numbers using time as seed

    for(int i = 1; i <= steps; i++)
    {
        int direction = rand() % 4; //generating random number between 0 and 3
        /*
        * 0 represents moving up
        * 1 represents moving down
        * 2 represents moving left
        * 3 represents moving right
        */

        switch(direction)
        {
            case 0:
                y++;
                printf("Step %d: Vehicle moved up. Current position: (%d,%d)\n",i,x,y);
                break;
            case 1:
                y--;
                printf("Step %d: Vehicle moved down. Current position: (%d,%d)\n",i,x,y);
                break;
            case 2:
                x--;
                printf("Step %d: Vehicle moved left. Current position: (%d,%d)\n",i,x,y);
                break;
            case 3:
                x++;
                printf("Step %d: Vehicle moved right. Current position: (%d,%d)\n",i,x,y);
                break;
        }
    }

    printf("Simulation completed!\n");
    printf("Final position of the vehicle: (%d,%d)\n",x,y);

    return 0;
}