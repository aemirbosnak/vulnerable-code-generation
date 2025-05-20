//FormAI DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#define MAX_SIZE 10

// Function declarations
void readMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void addMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void subtractMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);

// Main function
int main()
{
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the values for matrix A:\n");
    readMatrix(matrixA, rowsA, colsA);

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Enter the values for matrix B:\n");
    readMatrix(matrixB, rowsB, colsB);

    printf("Matrix A:\n");
    printMatrix(matrixA, rowsA, colsA);

    printf("Matrix B:\n");
    printMatrix(matrixB, rowsB, colsB);

    // Matrix addition
    if (rowsA == rowsB && colsA == colsB)
    {
        printf("Matrix A + Matrix B:\n");
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printMatrix(result, rowsA, colsA);
    }
    else
    {
        printf("Cannot perform matrix addition. Dimensions do not match.\n");
    }

    // Matrix subtraction
    if (rowsA == rowsB && colsA == colsB)
    {
        printf("Matrix A - Matrix B:\n");
        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        printMatrix(result, rowsA, colsA);
    }
    else
    {
        printf("Cannot perform matrix subtraction. Dimensions do not match.\n");
    }

    // Matrix multiplication
    if (colsA == rowsB)
    {
        printf("Matrix A * Matrix B:\n");
        multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, rowsB, colsB);
        printMatrix(result, rowsA, colsB);
    }
    else
    {
        printf("Cannot perform matrix multiplication. Incorrect dimensions.\n");
    }

    return 0;
}

// Function definitions

void readMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB)
{
    int i, j, k;

    for (i = 0; i < rowsA; i++)
    {
        for (j = 0; j < colsB; j++)
        {
            result[i][j] = 0;

            for (k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}