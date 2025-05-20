//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, m, i, j, x, y, z;
    char **a;

    n = rand() % 10 + 10;
    m = rand() % 10 + 10;
    a = (char **)malloc(n * sizeof(char *) + 1);
    for (i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(m * sizeof(char) + 1);
        for (j = 0; j < m; j++)
        {
            a[i][j] = rand() % 2;
        }
    }

    x = rand() % n;
    y = rand() % m;
    z = rand() % n;
    while (x == z)
    {
        z = rand() % n;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 1 && (i == x || j == y) && a[z][j] == 1)
            {
                a[i][j] = 2;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}