//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x, y, i, j, k, l, m, n;
    char c, d, e, f, g, h, *p, *q, **r;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    r = (char**)malloc(n * m * sizeof(char*));

    for (i = 0; i < n; i++)
    {
        r[i] = (char*)malloc(m * sizeof(char));
    }

    printf("Enter the characters to be used: ");
    scanf("%c %c %c", &c, &d, &e);

    printf("Enter the number of iterations: ");
    scanf("%d", &k);

    for (l = 0; l < k; l++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                r[i][j] = (rand() % 3) + c;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", r[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(r[i]);
    }

    free(r);

    return 0;
}