//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t start, end;
    start = time(NULL);

    // Vehicle Simulation
    int x = 0, y = 0, direction = 0;
    char key;

    // Controls
    while (1)
    {
        key = getchar();

        switch (key)
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
                end = time(NULL);
                printf("Time taken: %ld seconds\n", end - start);
                exit(0);
            default:
                break;
        }

        // Boundary Conditions
        if (x < 0)
            x = 0;
        if (x > 5)
            x = 5;
        if (y < 0)
            y = 0;
        if (y > 5)
            y = 5;

        // Print Vehicle Position
        printf("Vehicle at: (%d, %d)\n", x, y);
    }
}