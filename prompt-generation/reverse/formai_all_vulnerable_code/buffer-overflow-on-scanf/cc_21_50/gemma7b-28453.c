//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char grid[10][10] = {{0}};
    int x, y, i, j, k, l, m, n;
    char direction = 'H';

    printf("Enter the dimensions of the grid (n x m): ");
    scanf("%d %d", &n, &m);

    printf("Enter the number of iterations: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        switch (direction)
        {
            case 'H':
                for (x = 0; x < n; x++)
                {
                    for (y = 0; y < m; y++)
                    {
                        if (grid[x][y] == 0)
                        {
                            grid[x][y] = 1;
                        }
                    }
                }
                direction = 'V';
                break;
            case 'V':
                for (y = 0; y < m; y++)
                {
                    for (x = 0; x < n; x++)
                    {
                        if (grid[x][y] == 0)
                        {
                            grid[x][y] = 1;
                        }
                    }
                }
                direction = 'R';
                break;
            case 'R':
                for (x = n - 1; x >= 0; x--)
                {
                    for (y = 0; y < m; y++)
                    {
                        if (grid[x][y] == 0)
                        {
                            grid[x][y] = 1;
                        }
                    }
                }
                direction = 'T';
                break;
            case 'T':
                for (y = m - 1; y >= 0; y--)
                {
                    for (x = 0; x < n; x++)
                    {
                        if (grid[x][y] == 0)
                        {
                            grid[x][y] = 1;
                        }
                    }
                }
                direction = 'H';
                break;
        }
    }

    printf("The generated ASCII art:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", grid[i][j] == 1 ? '*' : ' ');
        }
        printf("\n");
    }

    return 0;
}