//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

// Function to create a matrix
void createMatrix(int rows, int cols, int matrix[rows][cols])
{
    printf("Enter the elements of the matrix:\n");

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print the matrix
void printMatrix(int rows, int cols, int matrix[rows][cols])
{
    printf("\nThe entered matrix is:\n");

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

//Function to subtract two matrices
void subtractMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    if(cols1 != rows2)
    {
        printf("\nMatrix multiplication not possible.\n");
        return;
    }

    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            result[i][j] = 0;

            for(int k=0; k<cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main()
{
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of matrix 1:\n");
    scanf("%d %d", &rows1, &cols1);

    int matrix1[rows1][cols1];

    createMatrix(rows1, cols1, matrix1);

    printMatrix(rows1, cols1, matrix1);

    printf("\nEnter the number of rows and columns of matrix 2:\n");
    scanf("%d %d", &rows2, &cols2);

    int matrix2[rows2][cols2];

    createMatrix(rows2, cols2, matrix2);

    printMatrix(rows2, cols2, matrix2);

    int result[rows1][cols1];

    // Add two matrices
    addMatrix(rows1, cols1, matrix1, matrix2, result);

    printf("\nAddition of two matrices:\n");

    printMatrix(rows1, cols1, result);

    // Subtract two matrices
    subtractMatrix(rows1, cols1, matrix1, matrix2, result);

    printf("\nSubtraction of two matrices:\n");

    printMatrix(rows1, cols1, result);

    // Multiply two matrices
    multiplyMatrix(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

    printf("\nMultiplication of two matrices:\n");

    printMatrix(rows1, cols2, result);

    return 0;
}