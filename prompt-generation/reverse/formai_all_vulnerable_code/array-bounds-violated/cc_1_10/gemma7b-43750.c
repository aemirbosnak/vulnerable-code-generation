//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
    int maze[MAX][MAX] = {{0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
                              {1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                              {0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
                              {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int x = 0, y = 0, direction = 0, goalx = 5, goalY = 5;

    time_t start, end;

    start = time(NULL);

    while (x != goalx || y != goalY)
    {
        switch (direction)
        {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
        }

        if (maze[x][y] == 1)
        {
            direction = (direction + 1) % 4;
        }
    }

    end = time(NULL);

    printf("Time taken: %ld seconds\n", end - start);

    return 0;
}