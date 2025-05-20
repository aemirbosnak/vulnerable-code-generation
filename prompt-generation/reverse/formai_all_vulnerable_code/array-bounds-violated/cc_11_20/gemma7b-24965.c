//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
    int x = 0, y = 0, d = 0, n = 0, i, j;
    int maze[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                            };

    system("clear");

    // Draw the maze
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("# ");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Get the user's input
    printf("Enter the number of the room you want to go to: ");
    scanf("%d", &n);

    // Find the route to the room
    while (n != maze[x][y])
    {
        // Calculate the direction of the next move
        if (maze[x][y - 1] == 1)
        {
            d = 2;
        }
        else if (maze[x + 1][y] == 1)
        {
            d = 1;
        }
        else if (maze[x][y + 1] == 1)
        {
            d = 3;
        }
        else if (maze[x - 1][y] == 1)
        {
            d = 4;
        }

        // Move in the direction of the next move
        switch (d)
        {
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                y++;
                break;
            case 4:
                x--;
                break;
        }

        // Draw the maze with the route
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                if (maze[i][j] == 1)
                {
                    printf("# ");
                }
                else if (maze[i][j] == 2)
                {
                    printf("X ");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Check if the room has been reached
        if (maze[x][y] == n)
        {
            printf("You have reached the room!");
        }
    }

    return 0;
}