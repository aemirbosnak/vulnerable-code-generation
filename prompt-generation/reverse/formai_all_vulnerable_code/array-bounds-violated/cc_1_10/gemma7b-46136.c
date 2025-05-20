//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int x, y, n, i, j, found = 0;
    char maze[MAX][MAX] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' '}};

    printf("Enter the number of moves: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the direction (N/S/E/W): ");
        scanf(" %c", &x);

        switch (x)
        {
            case 'N':
                y = -1;
                break;
            case 'S':
                y = 1;
                break;
            case 'E':
                y = 0;
                break;
            case 'W':
                y = 0;
                break;
            default:
                printf("Invalid direction\n");
                continue;
        }

        if (maze[y][x] == 'E')
        {
            found = 1;
            break;
        }

        maze[y][x] = 'M';
    }

    if (found)
    {
        printf("Congratulations! You found the exit!\n");
    }
    else
    {
        printf("Sorry, you did not find the exit.\n");
    }

    return 0;
}