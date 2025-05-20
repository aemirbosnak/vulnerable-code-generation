//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int i, j, k, n, m, p, q, flag, t;
    float a[10][10], b[10][10], c[10][10], sum = 0;
    char ch;

    printf("\n");
    printf("\t\t\t\t Welcome to the Cyberpunk Calculator\n");
    printf("\t\t\t\t-----------------------------------\n");
    printf("\n");

    srand(time(NULL));

    do
    {
        printf("\n");
        printf("\t\t\t\t Enter the number of rows and columns (max 10): ");
        scanf("%d%d", &n, &m);
    } while (n > 10 || m > 10);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            do
            {
                printf("\n");
                printf("\t\t\t\t Enter element a(%d,%d): ", i, j);
                scanf("%f", &a[i][j]);
            } while (a[i][j] == 0);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            b[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                b[i][j] += a[i][k] * a[k][j];
            }
        }
    }

    printf("\n");
    printf("\t\t\t\t The inverse of the matrix is:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] += a[k][j] * b[k][i];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("\t\t\t\t %.2f", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}