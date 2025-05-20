//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int maze[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
                           {1, 1, 1, 1, 1, 0, 0, 1, 0, 0},
                           {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int x = 0, y = 0, direction = 0, goalx = 5, goalY = 5;

    system("cls");

    while (x != goalx || y != goalY)
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
            direction = (direction + 1) % 4;
        }

        system("cls");

        maze[x][y] = 2;

        printf("x: %d, y: %d, direction: %d\n", x, y, direction);

        sleep(1);
    }

    system("cls");

    printf("You have reached the goal!");

    sleep(2);

    return 0;
}