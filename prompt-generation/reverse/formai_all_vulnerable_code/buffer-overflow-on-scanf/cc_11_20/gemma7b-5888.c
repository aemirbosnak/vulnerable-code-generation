//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELAY 25

void main()
{
    int i, j, x, y, direction = 0;
    char cmd;

    x = y = 0;

    while (1)
    {
        printf("Enter command (h/w/s/n/q): ");
        scanf(" %c", &cmd);

        switch (cmd)
        {
            case 'h':
                direction = 1;
                break;
            case 'w':
                direction = 2;
                break;
            case 's':
                direction = 3;
                break;
            case 'n':
                direction = 4;
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command.\n");
                break;
        }

        switch (direction)
        {
            case 1:
                x++;
                break;
            case 2:
                y++;
                break;
            case 3:
                x--;
                break;
            case 4:
                y--;
                break;
        }

        printf("C-Robot position: (%d, %d)\n", x, y);

        for (i = 0; i < DELAY; i++)
        {
            for (j = 0; j < DELAY; j++)
            {
                printf(".");
            }
            printf("\r");
        }

    }
}