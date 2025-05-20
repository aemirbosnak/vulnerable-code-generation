//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int maze[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
                              {1, 1, 1, 0, 0, 0, 1, 0, 0, 0},
                              {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                              {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int x = 0, y = 0, direction = 1;

    system("clear");

    while (maze[x][y] != 2)
    {
        switch (direction)
        {
            case 1:
                y++;
                break;
            case 2:
                x++;
                break;
            case 3:
                y--;
                break;
            case 4:
                x--;
                break;
        }

        if (maze[x][y] == 1)
        {
            direction++;
            if (direction > 4)
                direction = 1;
        }

        printf("%c", maze[x][y] + 32);
    }

    printf("\nYou have reached the end of the maze!");

    return 0;
}