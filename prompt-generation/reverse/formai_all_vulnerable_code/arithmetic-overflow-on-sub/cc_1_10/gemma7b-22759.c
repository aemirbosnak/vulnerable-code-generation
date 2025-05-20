//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int maze[MAX][MAX] = {{0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
                           {0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
                           {1, 1, 1, 0, 0, 0, 0, 0, 1, 0},
                           {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int x = 0, y = 0, direction = 0;

    printf("Enter the number of the target cell (x, y): ");
    scanf("%d %d", &x, &y);

    while (x != maze[y][x] || y != maze[y][x])
    {
        switch (direction)
        {
            case 0:
                y--;
                break;
            case 1:
                x++;
                break;
            case 2:
                y++;
                break;
            case 3:
                x--;
                break;
        }

        if (maze[y][x] == 0)
        {
            direction = (direction + 1) % 4;
        }
    }

    printf("The target cell is found at (x, y): (%d, %d)\n", x, y);

    return 0;
}