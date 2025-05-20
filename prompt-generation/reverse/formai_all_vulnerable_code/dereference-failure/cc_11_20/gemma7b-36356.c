//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, r;
    char **a = NULL, **b = NULL;

    n = rand() % 10 + 1;
    m = rand() % 20 + 1;

    a = (char**)malloc(n * sizeof(char*));
    b = (char**)malloc(m * sizeof(char*));

    for (i = 0; i < n; i++)
    {
        a[i] = (char*)malloc(m * sizeof(char));
    }

    for (i = 0; i < m; i++)
    {
        b[i] = (char*)malloc(n * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < rand() % 10; k++)
            {
                a[i][j] = (char)rand() % 26 + 97;
            }
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < rand() % 10; k++)
            {
                b[i][j] = (char)rand() % 26 + 97;
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

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);

    return 0;
}