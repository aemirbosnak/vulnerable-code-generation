//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;

    a = (int **)malloc(sizeof(int *) * 2);
    b = (int **)malloc(sizeof(int *) * 2);
    c = (int **)malloc(sizeof(int *) * 2);

    for (int i = 0; i < 2; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * 2);
        b[i] = (int *)malloc(sizeof(int) * 2);
        c[i] = (int *)malloc(sizeof(int) * 2);
    }

    // Loading the Matrix
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    // Transpose the Matrix
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            b[j][i] = a[i][j];
        }
    }

    // Multiply the Matrix by the Transpose
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c[i][j] += b[k][i] * a[k][j];
            }
        }
    }

    // Displaying the Result
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Freeing Memory
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            free(a[i][j]);
            free(b[i][j]);
            free(c[i][j]);
        }
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    return 0;
}