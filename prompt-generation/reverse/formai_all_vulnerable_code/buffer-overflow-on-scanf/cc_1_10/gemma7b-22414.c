//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t start = time(NULL);
    int i = 0;
    char cmd;
    int x = 0, y = 0;
    int speed = 0;
    char color = 'r';

    while (time(NULL) - start < 10)
    {
        printf("Enter command (s, w, a, d, r, b): ");
        scanf(" %c", &cmd);

        switch (cmd)
        {
            case 's':
                speed = 5;
                break;
            case 'w':
                speed = -5;
                break;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            case 'r':
                color = 'b';
                break;
            case 'b':
                color = 'r';
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        x = constrain(x, -10, 10);
        y = constrain(y, -10, 10);

        printf("Car position: (%d, %d)\n", x, y);
        printf("Speed: %d\n", speed);
        printf("Color: %c\n", color);

        sleep(1);
    }

    return 0;
}

int constrain(int value, int min, int max)
{
    if (value < min)
    {
        return min;
    }
    else if (value > max)
    {
        return max;
    }
    else
    {
        return value;
    }
}