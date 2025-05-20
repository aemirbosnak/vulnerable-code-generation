//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int maze[MAX][MAX] = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
                           {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
                           {1, 1, 1, 1, 0, 0, 0, 1, 1, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int x = 0, y = 0, direction = 0;

    printf("Enter the starting position (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the direction (0 for north, 1 for east, 2 for south, 3 for west): ");
    scanf("%d", &direction);

    while (maze[x][y] != 1)
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

        if (maze[x][y] == 0)
        {
            printf("Invalid move!\n");
            return 1;
        }
    }

    printf("Congratulations! You have reached the end of the maze.\n");

    return 0;
}