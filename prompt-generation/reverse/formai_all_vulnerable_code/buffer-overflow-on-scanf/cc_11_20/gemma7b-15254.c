//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0, y = 0, direction = 0;
    char input;

    while (1)
    {
        // Get user input
        scanf(" %c", &input);

        // Control robot movement
        switch (input)
        {
            case 'w':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y--;
                break;
            case 'd':
                x++;
                break;
            case 'q':
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Print robot position
        printf("Robot position: (%d, %d)\n", x, y);

        // Update direction
        if (x > 0)
        {
            direction = 1;
        }
        else if (x < 0)
        {
            direction = 3;
        }
        else
        {
            direction = 2;
        }

        // Move robot in direction
        switch (direction)
        {
            case 1:
                printf("Robot moving right...\n");
                break;
            case 2:
                printf("Robot stationary...\n");
                break;
            case 3:
                printf("Robot moving left...\n");
                break;
        }
    }

    return 0;
}