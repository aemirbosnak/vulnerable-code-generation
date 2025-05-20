//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 5
#define MIN_SPEED 0

int main()
{
    int speed = 0;
    char direction = ' ';
    bool engineOn = false;
    
    while (true)
    {
        printf("Enter command: ");
        scanf("%c", &direction);
        fflush(stdin);
        
        if (direction == 'q')
        {
            printf("Exiting program.\n");
            break;
        }
        else if (direction == 'o')
        {
            engineOn = true;
            printf("Engine turned on.\n");
        }
        else if (direction == 'f')
        {
            if (engineOn)
            {
                if (speed < MAX_SPEED)
                {
                    speed++;
                    printf("Speed increased to %d.\n", speed);
                }
                else
                {
                    printf("Cannot increase speed. Maximum speed reached.\n");
                }
            }
            else
            {
                printf("Cannot increase speed. Engine is turned off.\n");
            }
        }
        else if (direction == 's')
        {
            if (engineOn)
            {
                if (speed > MIN_SPEED)
                {
                    speed--;
                    printf("Speed decreased to %d.\n", speed);
                }
                else
                {
                    printf("Cannot decrease speed. Minimum speed reached.\n");
                }
            }
            else
            {
                printf("Cannot decrease speed. Engine is turned off.\n");
            }
        }
        else if (direction == 'c')
        {
            engineOn = false;
            speed = 0;
            printf("Engine turned off.\n");
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}