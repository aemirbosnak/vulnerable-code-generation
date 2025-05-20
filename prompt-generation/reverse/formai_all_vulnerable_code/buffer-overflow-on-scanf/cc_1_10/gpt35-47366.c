//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>

void printMatrix(int matrix[10][10], int rows, int cols)
{
    printf("\nMatrix:\n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void addMatrix(int matrix1[10][10], int matrix2[10][10], int result[10][10], int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
}

void multiplyMatrix(int matrix1[10][10], int matrix2[10][10], int result[10][10], int rows1, int cols1, int rows2, int cols2)
{
    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            result[i][j] = 0;
            for(int k=0; k<cols1; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

int main()
{
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("\nEnter the elements of first matrix:\n");
    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols1; j++)
            scanf("%d", &matrix1[i][j]);
    }

    printf("\nEnter the number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    printf("\nEnter the elements of second matrix:\n");
    for(int i=0; i<rows2; i++)
    {
        for(int j=0; j<cols2; j++)
            scanf("%d", &matrix2[i][j]);
    }

    if(cols1 != rows2)
    {
        printf("\nInvalid matrices! Columns of first matrix should be equal to rows of second matrix.\n");
        return 0;
    }

    // matrix addition 
    addMatrix(matrix1, matrix2, result, rows1, cols1);

    printf("\n\nAddition:\n");
    printMatrix(result, rows1, cols1);

    // matrix multiplication
    multiplyMatrix(matrix1, matrix2, result, rows1, cols1, rows2, cols2);

    printf("\n\nMultiplication:\n");
    printMatrix(result, rows1, cols2);

    return 0;
}