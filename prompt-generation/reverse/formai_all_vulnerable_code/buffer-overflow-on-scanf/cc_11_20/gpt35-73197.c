//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x = 0, y = 0; // initial position of the drone
   int command;
   while(1) // infinite loop until the drone is manually turned off
   {
        printf("Enter command: ");
        scanf("%d", &command);
        switch(command)
        {
            case 1:
                x++; // move the drone one step forward on x-axis
                printf("Drone moved to (%d, %d) \n", x, y);
                break;
            case 2:
                x--; // move the drone one step backward on x-axis
                printf("Drone moved to (%d, %d) \n", x, y);
                break;
            case 3:
                y++; // move the drone one step forward on y-axis
                printf("Drone moved to (%d, %d) \n", x, y);
                break;
            case 4:
                y--; // move the drone one step backward on y-axis
                printf("Drone moved to (%d, %d) \n", x, y);
                break;
            case 5:
                printf("Drone turned left \n"); // turn the drone left
                break;
            case 6:
                printf("Drone turned right \n"); // turn the drone right
                break;
            case 7:
                printf("Drone ascending \n"); // drone ascending
                break;
            case 8:
                printf("Drone descending \n"); // drone descending
                break;
            case 9:
                printf("Drone stopped \n"); // drone stopped
                break;
            case 10:
                printf("Drone landing... \n"); // landing the drone
                exit(0); // exit the program
            default:
                printf("Invalid command, try again! \n");
                break;
        }
   }
   return 0;
}