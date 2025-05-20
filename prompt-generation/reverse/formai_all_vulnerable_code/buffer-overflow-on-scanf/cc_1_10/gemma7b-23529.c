//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10

int main()
{
    int speed = 0;
    int direction = 1;
    char input = ' ';

    while (input != 'q')
    {
        printf("Enter command (w, a, s, d, q): ");
        scanf(" %c", &input);

        switch (input)
        {
            case 'w':
                speed++;
                if (speed > MAX_SPEED)
                {
                    speed = MAX_SPEED;
                }
                break;
            case 'a':
                direction = -1;
                break;
            case 's':
                speed--;
                if (speed < 0)
                {
                    speed = 0;
                }
                break;
            case 'd':
                direction = 1;
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        // Simulate movement
        printf("Car is moving %d km/h in direction %c.\n", speed, direction);
    }

    return 0;
}