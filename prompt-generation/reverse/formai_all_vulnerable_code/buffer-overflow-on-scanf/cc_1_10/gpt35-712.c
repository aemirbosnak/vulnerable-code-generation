//FormAI DATASET v1.0 Category: Matrix operations ; Style: content
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void printMatrix(int **matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to create a matrix of given size
int **createMatrix(int rows, int columns)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }
    return matrix;
}

// Function to add two matrices of same size
int **addMatrices(int **matrix1, int **matrix2, int rows, int columns)
{
    int **sumMatrix = createMatrix(rows, columns);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return sumMatrix;
}

// Function to subtract two matrices of same size
int **subtractMatrices(int **matrix1, int **matrix2, int rows, int columns)
{
    int **differenceMatrix = createMatrix(rows, columns);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            differenceMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return differenceMatrix;
}

// Function to multiply two matrices
int **multiplyMatrices(int **matrix1, int rows1, int columns1, int **matrix2, int rows2, int columns2)
{
    int **productMatrix = createMatrix(rows1, columns2);
    for(int i = 0; i < rows1; i++)
    {
        for(int j = 0; j < columns2; j++)
        {
            for(int k = 0; k < rows2; k++)
            {
                productMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return productMatrix;
}

int main()
{
    int rows1, columns1, rows2, columns2;
    printf("Enter the number of rows of matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns of matrix 1: ");
    scanf("%d", &columns1);

    int **matrix1 = createMatrix(rows1, columns1);

    printf("Enter the elements of the matrix 1:\n");
    for(int i = 0; i < rows1; i++)
    {
        for(int j = 0; j < columns1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows of matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns of matrix 2: ");
    scanf("%d", &columns2);

    int **matrix2 = createMatrix(rows2, columns2);

    printf("Enter the elements of the matrix 2:\n");
    for(int i = 0; i < rows2; i++)
    {
        for(int j = 0; j < columns2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, columns1);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows2, columns2);

    if(rows1 != rows2 || columns1 != columns2)
    {
        printf("\nMatrices cannot be added or subtracted due to different sizes.\n");
    }
    else
    {
        int **sumMatrix = addMatrices(matrix1, matrix2, rows1, columns1);
        int **differenceMatrix = subtractMatrices(matrix1, matrix2, rows1, columns1);

        printf("\nMatrix 1 + Matrix 2:\n");
        printMatrix(sumMatrix, rows1, columns1);

        printf("\nMatrix 1 - Matrix 2:\n");
        printMatrix(differenceMatrix, rows1, columns1);

        for(int i = 0; i < rows1; i++)
        {
            free(sumMatrix[i]);
            free(differenceMatrix[i]);
        }
        free(sumMatrix);
        free(differenceMatrix);
    }

    if(columns1 != rows2)
    {
        printf("\nMatrices cannot be multiplied due to incompatible sizes.\n");
    }
    else
    {
        int **productMatrix = multiplyMatrices(matrix1, rows1, columns1, matrix2, rows2, columns2);

        printf("\nMatrix 1 * Matrix 2:\n");
        printMatrix(productMatrix, rows1, columns2);

        for(int i = 0; i < rows1; i++)
        {
            free(productMatrix[i]);
        }
        free(productMatrix);
    }

    for(int i = 0; i < rows1; i++)
    {
        free(matrix1[i]);
    }
    for(int i = 0; i < rows2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);

    return 0;
}