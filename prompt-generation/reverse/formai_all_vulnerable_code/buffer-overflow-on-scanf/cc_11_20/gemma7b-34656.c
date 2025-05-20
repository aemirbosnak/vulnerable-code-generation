//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int n = 0, m = 0, i = 0, j = 0, k = 0;

    printf("Loading... Agent Smith's neural network...\n");

    // Matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Enter number of columns: ");
    scanf("%d", &m);

    // Allocate memory
    a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(m * sizeof(int));
    }

    b = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        b[i] = (int*)malloc(m * sizeof(int));
    }

    c = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        c[i] = (int*)malloc(m * sizeof(int));
    }

    // Input data
    printf("Enter matrix A elements: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }

    printf("Enter matrix B elements: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d ", &b[i][j]);
        }
    }

    // Matrix operations
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Output results
    printf("The product of matrices A and B is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            free(a[i][j]);
        }
        free(a[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}