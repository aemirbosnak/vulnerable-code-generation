//Falcon-180B DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n, m, sum = 0;
    int **matrix1, **matrix2, **result;
    int rows1, cols1, rows2, cols2;

    // User input for the dimensions of the matrices
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    // Allocate memory for the matrices
    matrix1 = (int **)malloc(rows1 * sizeof(int *));
    matrix2 = (int **)malloc(rows2 * sizeof(int *));
    result = (int **)malloc(rows1 * sizeof(int *));
    for (i = 0; i < rows1; i++)
    {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // User input for the elements of the matrices
    printf("Enter the elements of matrix 1: ");
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the elements of matrix 2: ");
    for (i = 0; i < rows2; i++)
    {
        for (j = 0; j < cols2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Matrix multiplication
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols2; j++)
        {
            for (m = 0; m < cols1; m++)
            {
                sum += matrix1[i][m] * matrix2[m][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }

    // Display the result matrix
    printf("Result of matrix multiplication:\n");
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < rows1; i++)
    {
        free(matrix1[i]);
        free(result[i]);
    }
    for (i = 0; i < rows2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}