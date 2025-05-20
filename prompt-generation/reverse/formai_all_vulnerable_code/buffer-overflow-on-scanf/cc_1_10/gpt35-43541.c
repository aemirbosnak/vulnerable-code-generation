//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>

//function to print the matrix
void printMatrix(int matrix[][100], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

//function to add two matrices
void addMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
}

//function to subtract two matrices
void subtractMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
}

//function to multiply two matrices
void multiplyMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows1, int cols1, int rows2, int cols2)
{
    int i, j, k;

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main()
{
    int rows1, cols1, rows2, cols2;
    int matrix1[100][100], matrix2[100][100], result[100][100];
    int choice;

    //getting dimensions of first matrix
    printf("Enter number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    //getting elements of first matrix
    printf("Enter elements of first matrix:\n");
    int i, j;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            printf("Enter element at[%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    //getting dimensions of second matrix
    printf("Enter number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    //getting elements of second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            printf("Enter element at[%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    //menu to select operation
    printf("\nSelect operation:\n");
    printf("1. Add matrices\n");
    printf("2. Subtract matrices\n");
    printf("3. Multiply matrices\n");

    //get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        //add the two matrices
        if (rows1 != rows2 || cols1 != cols2) {
            printf("Matrices cannot be added!\n");
            return -1;
        }
        addMatrices(matrix1, matrix2, result, rows1, cols1);
        printf("\nResultant matrix:\n");
        printMatrix(result, rows1, cols1);
        break;

    case 2:
        //subtract the two matrices
        if (rows1 != rows2 || cols1 != cols2) {
            printf("Matrices cannot be subtracted!\n");
            return -1;
        }
        subtractMatrices(matrix1, matrix2, result, rows1, cols1);
        printf("\nResultant matrix:\n");
        printMatrix(result, rows1, cols1);
        break;

    case 3:
        //multiply the two matrices
        if (cols1 != rows2) {
            printf("Matrices cannot be multiplied!\n");
            return -1;
        }
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
        printf("\nResultant matrix:\n");
        printMatrix(result, rows1, cols2);
        break;

    default:
        printf("Invalid choice!\n");
        return -1;
        break;
    }

    return 0;
}