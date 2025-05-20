//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x = 0, y = 0, d = 0;
    char grid[10][10] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    while (1)
    {
        switch (d)
        {
            case 0:
                grid[x][y] = 'C';
                y++;
                break;
            case 1:
                grid[x][y] = 'C';
                x++;
                break;
            case 2:
                grid[x][y] = 'C';
                y--;
                break;
            case 3:
                grid[x][y] = 'C';
                x--;
                break;
            default:
                break;
        }

        if (grid[x][y] == 'W')
        {
            printf("GAME OVER!\n");
            exit(0);
        }

        printf("Current position: (%d, %d)\n", x, y);
        printf("Direction: %d\n", d);
        printf("Grid:\n");
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }

        printf("Press any key to continue...");
        getchar();
    }
}