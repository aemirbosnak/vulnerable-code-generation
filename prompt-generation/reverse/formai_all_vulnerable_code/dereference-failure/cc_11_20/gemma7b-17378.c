//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;

    // Allocate memory for the matrices
    a = (int**)malloc(5 * sizeof(int*));
    for(int i = 0; i < 5; i++)
    {
        a[i] = (int*)malloc(5 * sizeof(int));
    }

    b = (int**)malloc(5 * sizeof(int*));
    for(int i = 0; i < 5; i++)
    {
        b[i] = (int*)malloc(5 * sizeof(int));
    }

    c = (int**)malloc(5 * sizeof(int*));
    for(int i = 0; i < 5; i++)
    {
        c[i] = (int*)malloc(5 * sizeof(int));
    }

    // Initialize the matrices
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    // Perform the matrix multiplication
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            c[i][j] = 0;
            for(int k = 0; k < 5; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print the result
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
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