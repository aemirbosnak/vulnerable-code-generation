//FormAI DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void initializeMatrix(int rows, int cols, float **matrix);
void printMatrix(int rows, int cols, float **matrix);
void addMatrices(int rows, int cols, float **matrix1, float **matrix2, float **result);
void subtractMatrices(int rows, int cols, float **matrix1, float **matrix2, float **result);
void multiplyMatrices(int rows1, int cols1, int rows2, int cols2, float **matrix1, float **matrix2, float **result);

int main()
{
    int rows1, cols1, rows2, cols2;

    // Get matrix 1 dimensions
    printf("Enter the number of rows in matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns in matrix 1: ");
    scanf("%d", &cols1);

    // Get matrix 2 dimensions
    printf("Enter the number of rows in matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns in matrix 2: ");
    scanf("%d", &cols2);

    // Check if the matrices can be multiplied
    if (cols1 != rows2)
    {
        printf("Matrices cannot be multiplied!");
        return 0;
    }

    // Allocate memory for the matrices
    float **matrix1 = (float **)malloc(rows1 * sizeof(float *));
    float **matrix2 = (float **)malloc(rows2 * sizeof(float *));
    float **result = (float **)malloc(rows1 * sizeof(float *));

    for (int i = 0; i < rows1; i++)
    {
        matrix1[i] = (float *)malloc(cols1 * sizeof(float));
        result[i] = (float *)malloc(cols2 * sizeof(float));
    }

    for (int i = 0; i < rows2; i++)
    {
        matrix2[i] = (float *)malloc(cols2 * sizeof(float));
    }

    // Initialize matrices with random values
    initializeMatrix(rows1, cols1, matrix1);
    initializeMatrix(rows2, cols2, matrix2);

    // Print the matrices
    printf("\nMatrix 1:\n");
    printMatrix(rows1, cols1, matrix1);

    printf("\nMatrix 2:\n");
    printMatrix(rows2, cols2, matrix2);

    // Add the matrices
    printf("\nMatrix 1 + Matrix 2:\n");
    addMatrices(rows1, cols1, matrix1, matrix2, result);
    printMatrix(rows1, cols2, result);

    // Subtract the matrices
    printf("\nMatrix 1 - Matrix 2:\n");
    subtractMatrices(rows1, cols1, matrix1, matrix2, result);
    printMatrix(rows1, cols2, result);

    // Multiply the matrices
    printf("\nMatrix 1 * Matrix 2:\n");
    multiplyMatrices(rows1, cols1, rows2, cols2, matrix1, matrix2, result);
    printMatrix(rows1, cols2, result);

    // Free the memory
    for (int i = 0; i < rows1; i++)
    {
        free(matrix1[i]);
        free(result[i]);
    }

    for (int i = 0; i < rows2; i++)
    {
        free(matrix2[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}

// Function to initialize a matrix with random values
void initializeMatrix(int rows, int cols, float **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = (float)rand() / RAND_MAX;
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, float **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int rows, int cols, float **matrix1, float **matrix2, float **result)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int rows, int cols, float **matrix1, float **matrix2, float **result)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int rows1, int cols1, int rows2, int cols2, float **matrix1, float **matrix2, float **result)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}