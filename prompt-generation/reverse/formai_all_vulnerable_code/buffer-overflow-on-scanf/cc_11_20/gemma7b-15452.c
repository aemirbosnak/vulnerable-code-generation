//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, i, j, k, l, x, y, z;
    int **a, **b, **c;

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of vertices: ");
        scanf("%d", &x);

        a = (int **)malloc(x * sizeof(int *));
        b = (int **)malloc(x * sizeof(int *));
        c = (int **)malloc(x * sizeof(int *));

        for (j = 0; j < x; j++)
        {
            a[j] = (int *)malloc(x * sizeof(int));
            b[j] = (int *)malloc(x * sizeof(int));
            c[j] = (int *)malloc(x * sizeof(int));
        }

        for (k = 0; k < x; k++)
        {
            for (l = 0; l < x; l++)
            {
                scanf("%d", &c[k][l]);
            }
        }

        for (k = 0; k < x; k++)
        {
            for (l = 0; l < x; l++)
            {
                a[k][l] = 0;
                b[k][l] = 0;
            }
        }

        for (k = 0; k < x; k++)
        {
            for (l = 0; l < x; l++)
            {
                if (c[k][l] == 1)
                {
                    a[k][l] = 1;
                    b[k][l] = 1;
                }
            }
        }

        for (k = 0; k < x; k++)
        {
            for (l = 0; l < x; l++)
            {
                printf("%d ", a[k][l]);
            }
            printf("\n");
        }

        for (k = 0; k < x; k++)
        {
            for (l = 0; l < x; l++)
            {
                free(c[k][l]);
            }
            free(b[k]);
            free(a[k]);
        }
    }

    return 0;
}