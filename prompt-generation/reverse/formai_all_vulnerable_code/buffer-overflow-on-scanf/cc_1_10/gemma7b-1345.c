//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char grid[10][10] = {{0}};
    int x, y, i, j, k, l, m, n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    printf("Enter the number of stars: ");
    scanf("%d", &k);

    for (x = 0; x < n; x++)
    {
        for (y = 0; y < m; y++)
        {
            grid[x][y] = 0;
        }
    }

    for (i = 0; i < k; i++)
    {
        printf("Enter the row number of star: ");
        scanf("%d", &l);

        printf("Enter the column number of star: ");
        scanf("%d", &j);

        grid[l][j] = 1;
    }

    for (x = 0; x < n; x++)
    {
        for (y = 0; y < m; y++)
        {
            if (grid[x][y] == 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }

        printf("\n");
    }

    return 0;
}