//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // The Matrix
    int **a = (int**)malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++)
    {
        a[i] = (int*)malloc(4 * sizeof(int));
    }

    // Initializing the Matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    // Transpose the Matrix
    int **b = (int**)malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++)
    {
        b[i] = (int*)malloc(4 * sizeof(int));
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            b[j][i] = a[i][j];
        }
    }

    // Print the Transposed Matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    // Free the Memory
    for (int i = 0; i < 4; i++)
    {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < 4; i++)
    {
        free(b[i]);
    }
    free(b);

    return 0;
}