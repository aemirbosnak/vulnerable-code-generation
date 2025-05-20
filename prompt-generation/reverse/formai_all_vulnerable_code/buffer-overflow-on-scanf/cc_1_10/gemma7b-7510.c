//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int direction = 0, speed = 0;
    char command;

    printf("Remote Control Vehicle Simulation\n");
    printf("------------------------\n");

    while (1)
    {
        printf("Enter command (F/B/L/R/S/P): ");
        scanf(" %c", &command);

        switch (command)
        {
            case 'F':
                direction = 1;
                speed = 5;
                break;
            case 'B':
                direction = -1;
                speed = 5;
                break;
            case 'L':
                direction = 0;
                speed = 3;
                break;
            case 'R':
                direction = 0;
                speed = 3;
                break;
            case 'S':
                direction = 0;
                speed = 0;
                break;
            case 'P':
                direction = 0;
                speed = 0;
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        if (direction != 0)
        {
            printf("Vehicle moving in direction %d at speed %d.\n", direction, speed);
        }
        else
        {
            printf("Vehicle stopped.\n");
        }
    }

    return 0;
}