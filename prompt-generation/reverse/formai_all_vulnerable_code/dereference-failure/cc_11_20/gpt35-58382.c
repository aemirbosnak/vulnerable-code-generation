//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row1, col1, row2, col2;

    // Requesting the user to input first matrix dimensions
    printf("Enter the number of rows of first matrix: ");
    scanf("%d", &row1);
    printf("Enter the number of columns of first matrix: ");
    scanf("%d", &col1);

    // Requesting the user to input second matrix dimensions
    printf("\nEnter the number of rows of second matrix: ");
    scanf("%d", &row2);
    printf("Enter the number of columns of second matrix: ");
    scanf("%d", &col2);

    // Validating the input dimensions
    if (col1 != row2)
    {
        printf("\nError: The number of columns of first matrix must be equal to the number of rows of second matrix.\n");
        return 0;
    }

    // Input arrays declaration
    int **matrix1 = (int **)malloc(row1 * sizeof(int *));
    int **matrix2 = (int **)malloc(row2 * sizeof(int *));
    int **resultMatrix = (int **)malloc(row1 * sizeof(int *));
    int i, j, k;

    // Dynamically allocate memory for matrix arrays
    for (i = 0; i < row1; i++)
    {
        matrix1[i] = (int *)malloc(col1 * sizeof(int));
        resultMatrix[i] = (int *)malloc(col2 * sizeof(int));
    }

    for (i = 0; i < row2; i++)
        matrix2[i] = (int *)malloc(col2 * sizeof(int));

    // Requesting values for first matrix
    printf("\nEnter the elements of first matrix:\n");
    for (i = 0; i < row1; i++)
        for (j = 0; j < col1; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }

    // Requesting values for second matrix
    printf("\nEnter the elements of second matrix:\n");
    for (i = 0; i < row2; i++)
        for (j = 0; j < col2; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }

    // Printing first matrix
    printf("\nFirst Matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
            printf("%d ", matrix1[i][j]);
        printf("\n");
    }

    // Printing second matrix
    printf("\nSecond Matrix:\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
            printf("%d ", matrix2[i][j]);
        printf("\n");
    }

    // Performing matrix multiplication
    int sum;
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            sum = 0;
            for (k = 0; k < row2; k++)
                sum += matrix1[i][k] * matrix2[k][j];
            resultMatrix[i][j] = sum;
        }
    }

    // Printing result matrix
    printf("\nMatrix multiplication result:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
            printf("%d ", resultMatrix[i][j]);
        printf("\n");
    }

    // Freeing matrix arrays memory
    for (i = 0; i < row1; i++)
    {
        free(matrix1[i]);
        free(resultMatrix[i]);
    }

    for (i = 0; i < row2; i++)
        free(matrix2[i]);

    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return 0;
}