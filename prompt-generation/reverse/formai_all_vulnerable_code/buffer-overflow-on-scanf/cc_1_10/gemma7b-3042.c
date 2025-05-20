//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int rows, cols, i, j, k, matrix_size = 0;

    printf("Enter the number of rows and columns of the matrix:");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for the matrices
    a = (int **)malloc(rows * sizeof(int *));
    b = (int **)malloc(rows * sizeof(int *));
    c = (int **)malloc(rows * sizeof(int *));

    // Get the size of the matrix
    matrix_size = rows * cols;

    // Initialize the matrices
    for (i = 0; i < rows; i++)
    {
        a[i] = (int *)malloc(cols * sizeof(int));
        b[i] = (int *)malloc(cols * sizeof(int));
        c[i] = (int *)malloc(cols * sizeof(int));
    }

    // Fill the matrices with sample data
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            a[i][j] = i + j;
            b[i][j] = 2 * i + 3 * j;
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print the results
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < rows; i++)
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