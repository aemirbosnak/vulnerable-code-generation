//FormAI DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
int **matrixMultiplication(int **a, int **b, int m, int n, int p)
{
    // Creating a new matrix for storing the result of matrix multiplication
    int **resultMatrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        resultMatrix[i] = (int *)malloc(p * sizeof(int));
    }

    // Performing matrix multiplication
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                resultMatrix[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return resultMatrix;
}

int main()
{
    int **matrixA, **matrixB, **resultMatrix;
    int rowsA, columnsA, rowsB, columnsB;

    // Taking input for matrix A
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &columnsA);

    matrixA = (int **)malloc(rowsA * sizeof(int *));
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = (int *)malloc(columnsA * sizeof(int));
        for (int j = 0; j < columnsA; j++)
        {
            printf("Enter element [%d][%d] of matrix A: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Taking input for matrix B
    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &columnsB);

    matrixB = (int **)malloc(rowsB * sizeof(int *));
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = (int *)malloc(columnsB * sizeof(int));
        for (int j = 0; j < columnsB; j++)
        {
            printf("Enter element [%d][%d] of matrix B: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Displaying matrices A and B
    printf("Matrix A:\n");
    displayMatrix(matrixA, rowsA, columnsA);
    printf("Matrix B:\n");
    displayMatrix(matrixB, rowsB, columnsB);

    // Performing matrix multiplication
    if (columnsA == rowsB)
    {
        resultMatrix = matrixMultiplication(matrixA, matrixB, rowsA, columnsA, columnsB);
        printf("Result Matrix:\n");
        displayMatrix(resultMatrix, rowsA, columnsB);
    }
    else
    {
        printf("Matrix multiplication cannot be performed for given matrices.\n");
    }

    return 0;
}