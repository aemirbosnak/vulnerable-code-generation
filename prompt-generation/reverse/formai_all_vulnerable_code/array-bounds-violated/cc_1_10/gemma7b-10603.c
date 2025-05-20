//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int maze[MAX][MAX] = {{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                           {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                           {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int x = 0, y = 0, direction = 0;
    char path[MAX][MAX] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};

    while (path[x][y] != 'z')
    {
        switch (direction)
        {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
        }

        if (maze[x][y] == 1)
        {
            path[x][y] = 'z';
            direction = (direction + 1) % 4;
        }
    }

    printf("The path is: ");
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%c ", path[i][j]);
        }
    }

    return 0;
}