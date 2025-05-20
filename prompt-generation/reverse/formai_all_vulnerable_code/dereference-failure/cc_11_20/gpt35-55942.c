//FormAI DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols, i, j;

    // Get input for number of rows and columns
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Create a 2D matrix of size rows x cols
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    // Get input for values in the matrix
    printf("Enter values for matrix of size %d x %d:\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("The matrix is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Find and print the transpose of the matrix
    printf("The transpose of the matrix is:\n");
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    // Find and print the sum of all elements in the matrix
    int sum = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }
    printf("The sum of all elements in the matrix is: %d\n", sum);

    // Free memory allocated for matrix
    for (i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    return 0;
}