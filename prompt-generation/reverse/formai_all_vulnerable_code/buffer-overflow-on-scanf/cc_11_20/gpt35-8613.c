//FormAI DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row1, col1, row2, col2, i, j, k; // Variables to hold matrix dimensions
    printf("Enter dimensions of Matrix 1: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter dimensions of Matrix 2: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) // To check if the matrices can be multiplied
    {
        printf("The matrices cannot be multiplied!\n");
        exit(0);
    }

    // Declaring matrices dynamically
    int **matrix1 = (int **)malloc(row1 * sizeof(int *));
    int **matrix2 = (int **)malloc(row2 * sizeof(int *));
    int **result = (int **)malloc(row1 * sizeof(int *));

    for (i = 0; i < row1; i++)
    {
        matrix1[i] = (int *)malloc(col1 * sizeof(int));
        result[i] = (int *)malloc(col2 * sizeof(int));
    }

    for (i = 0; i < row2; i++)
    {
        matrix2[i] = (int *)malloc(col2 * sizeof(int));
    }

    // Reading elements of Matrix 1
    printf("\nEnter elements of Matrix 1:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Reading elements of Matrix 2
    printf("\nEnter elements of Matrix 2:\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Performing matrix multiplication
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            for (k = 0; k < row2; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nResultant Matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Freeing dynamically allocated memory
    for (i = 0; i < row1; i++)
    {
        free(matrix1[i]);
        free(result[i]);
    }

    for (i = 0; i < row2; i++)
    {
        free(matrix2[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}