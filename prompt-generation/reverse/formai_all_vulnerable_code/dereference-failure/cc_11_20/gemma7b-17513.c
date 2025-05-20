//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;
    int i, j, k;

    // Allocate memory for matrices a, b, and c
    a = (int**)malloc(5 * sizeof(int*));
    for (i = 0; i < 5; i++)
        a[i] = (int*)malloc(5 * sizeof(int));

    b = (int**)malloc(5 * sizeof(int*));
    for (i = 0; i < 5; i++)
        b[i] = (int*)malloc(5 * sizeof(int));

    c = (int**)malloc(5 * sizeof(int*));
    for (i = 0; i < 5; i++)
        c[i] = (int*)malloc(5 * sizeof(int));

    // Initialize the matrices
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            a[i][j] = 0;
            b[i][j] = 0;
            c[i][j] = 0;
        }
    }

    // Perform Matrix Operations
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 5; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print the result
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < 5; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}