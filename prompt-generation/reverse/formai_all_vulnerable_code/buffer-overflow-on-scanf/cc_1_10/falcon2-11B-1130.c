//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

// Function to print a matrix
void print_matrix(int matrix[][100], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[][100], int matrix2[][100], int rows1, int cols1, int rows2, int cols2, int matrix3[][100])
{
    int i, j, k;
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols2; j++)
        {
            matrix3[i][j] = 0;
            for (k = 0; k < cols1; k++)
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

int main()
{
    int matrix1[100][100], matrix2[100][100], matrix3[100][100];
    int i, j, rows1, cols1, rows2, cols2;

    // Read the first matrix from the user
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d%d", &rows1, &cols1);
    printf("Enter the elements of matrix 1: ");
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols1; j++)
            scanf("%d", &matrix1[i][j]);
    }

    // Read the second matrix from the user
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d%d", &rows2, &cols2);
    printf("Enter the elements of matrix 2: ");
    for (i = 0; i < rows2; i++)
    {
        for (j = 0; j < cols2; j++)
            scanf("%d", &matrix2[i][j]);
    }

    // Multiply the two matrices and print the resulting matrix
    printf("The product of matrix 1 and matrix 2 is:\n");
    multiply_matrices(matrix1, matrix2, rows1, cols1, rows2, cols2, matrix3);
    print_matrix(matrix3, rows1, cols2);

    return 0;
}