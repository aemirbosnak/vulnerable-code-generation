//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 20

int main()
{
    int speed = 0;
    int direction = 0;
    char command;

    while (1)
    {
        printf("Enter command (s/n/r/p): ");
        scanf("%c", &command);

        switch (command)
        {
            case 's':
                if (speed < MAX_SPEED)
                {
                    speed++;
                    printf("Speed: %d\n", speed);
                }
                else
                {
                    printf("Max speed reached.\n");
                }
                break;
            case 'n':
                if (speed > 0)
                {
                    speed--;
                    printf("Speed: %d\n", speed);
                }
                else
                {
                    printf("Min speed reached.\n");
                }
                break;
            case 'r':
                direction = -direction;
                printf("Direction: %d\n", direction);
                break;
            case 'p':
                speed = 0;
                direction = 0;
                printf("Speed: %d\n", speed);
                printf("Direction: %d\n", direction);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}