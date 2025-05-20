//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void matrix_operations(int **a, int **b, int **c)
{
    int i, j, k;

    // Allocate memory for the result matrix c
    c = (int *)malloc(ROWS * COLS * sizeof(int));

    // Calculate the matrix product
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < COLS; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print the result
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for c
    free(c);
}

int main()
{
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;

    // Allocate memory for the matrices a and b
    a = (int *)malloc(ROWS * COLS * sizeof(int));
    b = (int *)malloc(ROWS * COLS * sizeof(int));

    // Initialize the matrices a and b
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;

    b[0][0] = 2;
    b[0][1] = 3;
    b[0][2] = 4;
    b[1][0] = 5;
    b[1][1] = 6;
    b[1][2] = 7;
    b[2][0] = 8;
    b[2][1] = 9;
    b[2][2] = 10;

    // Perform matrix operations
    matrix_operations(a, b, c);

    // Free the memory allocated for a, b, and c
    free(a);
    free(b);
    free(c);

    return 0;
}