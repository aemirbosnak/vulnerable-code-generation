#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0, y = 0;
    char direction;

    // 10x10 map
    char map[10][10] = {'#'};

    map[x][y] = 'P';

    while (1)
    {
        printf("Enter direction (N, S, E, W): ");
        scanf("%c", &direction);

        switch (direction)
        {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        // Out-of-bounds access
        if (x < 0 || x >= 10 || y < 0 || y >= 10)
        {
            printf("You have exceeded the bounds of the map.\n");
            return 1;
        }

        map[x][y] = 'P';
        printf("You are at (%d, %d).\n", x, y);
    }
}
