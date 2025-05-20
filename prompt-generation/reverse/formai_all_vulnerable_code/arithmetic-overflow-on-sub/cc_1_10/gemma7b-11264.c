//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x = 0, y = 0, z = 0, i = 0, j = 0, k = 0, direction = 1;
    char map[10][10] = {
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'S', 'S', 'S', 'S', 'S', 'A', 'A', 'A', 'A'},
        {'A', 'S', 'N', 'N', 'N', 'S', 'A', 'A', 'A', 'A'},
        {'A', 'S', 'N', 'E', 'N', 'S', 'A', 'A', 'A', 'A'},
        {'A', 'S', 'N', 'E', 'M', 'S', 'A', 'A', 'A', 'A'},
        {'A', 'S', 'N', 'E', 'M', 'S', 'A', 'A', 'A', 'A'},
        {'A', 'S', 'N', 'E', 'M', 'S', 'A', 'A', 'A', 'A'},
        {'A', 'S', 'N', 'E', 'M', 'S', 'A', 'A', 'A', 'A'},
        {'A', 'S', 'N', 'E', 'M', 'S', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    };

    time_t t = time(NULL);

    while (1)
    {
        switch (direction)
        {
            case 1:
                x++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y++;
                break;
            case 4:
                y--;
                break;
            default:
                break;
        }

        if (map[x][y] == 'S')
        {
            direction = 5;
        }

        if (time(NULL) - t >= 1)
        {
            t = time(NULL);
            printf("Current position: (%d, %d)\n", x, y);
            printf("Direction: %d\n", direction);
            printf("Map:\n");
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    printf("%c ", map[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    return 0;
}