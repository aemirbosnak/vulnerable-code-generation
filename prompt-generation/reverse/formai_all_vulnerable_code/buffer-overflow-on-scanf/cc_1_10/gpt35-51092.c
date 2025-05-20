//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>

// define matrix dimensions
#define ROW 2
#define COL 2

// function to read matrix from user input
void readMatrix(int matrix[][COL])
{
    printf("Enter the matrix elements:\n");
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// function to print matrix to console
void printMatrix(int matrix[][COL])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
void addMatrix(int matrix1[][COL], int matrix2[][COL], int result[][COL])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// function to subtract two matrices
void subMatrix(int matrix1[][COL], int matrix2[][COL], int result[][COL])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// function to multiply two matrices
void multiplyMatrix(int matrix1[][COL], int matrix2[][COL], int result[][COL])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < COL; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// function to get the transpose of a matrix
void transposeMatrix(int matrix[][COL], int result[][ROW])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

int main()
{
    int matrix1[ROW][COL], matrix2[ROW][COL], result[ROW][COL], transpose[COL][ROW];
    
    printf("Enter the first matrix:\n");
    readMatrix(matrix1);
    printf("Enter the second matrix:\n");
    readMatrix(matrix2);
    
    // add the two matrices
    addMatrix(matrix1, matrix2, result);
    printf("The sum of the matrices is:\n");
    printMatrix(result);
    
    // subtract the two matrices
    subMatrix(matrix1, matrix2, result);
    printf("The difference of the matrices is:\n");
    printMatrix(result);
    
    // multiply the two matrices
    multiplyMatrix(matrix1, matrix2, result);
    printf("The product of the matrices is:\n");
    printMatrix(result);
    
    // get the transpose of matrix1
    transposeMatrix(matrix1, transpose);
    printf("The transpose of the first matrix is:\n");
    printMatrix(transpose);
    
    return 0;
}