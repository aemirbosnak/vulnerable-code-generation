//FormAI DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to print the matrix
void print_matrix(int **matrix, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int **add_matrices(int **matrix1, int **matrix2, int size)
{
    int **result = (int **) malloc(sizeof(int *) * size);

    for(int i=0; i<size; i++)
    {
        result[i] = (int *) malloc(sizeof(int) * size);

        for(int j=0; j<size; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
int **subtract_matrices(int **matrix1, int **matrix2, int size)
{
    int **result = (int **) malloc(sizeof(int *) * size);

    for(int i=0; i<size; i++)
    {
        result[i] = (int *) malloc(sizeof(int) * size);

        for(int j=0; j<size; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices
int **multiply_matrices(int **matrix1, int **matrix2, int size)
{
    int **result = (int **) malloc(sizeof(int *) * size);

    for(int i=0; i<size; i++)
    {
        result[i] = (int *) malloc(sizeof(int) * size);

        for(int j=0; j<size; j++)
        {
            result[i][j] = 0;

            for(int k=0; k<size; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main()
{
    int size;

    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    int **matrix1 = (int **) malloc(sizeof(int *) * size);
    int **matrix2 = (int **) malloc(sizeof(int *) * size);

    printf("Enter the elements of the first matrix:\n");

    for(int i=0; i<size; i++)
    {
        matrix1[i] = (int *) malloc(sizeof(int) * size);

        for(int j=0; j<size; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");

    for(int i=0; i<size; i++)
    {
        matrix2[i] = (int *) malloc(sizeof(int) * size);

        for(int j=0; j<size; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    print_matrix(matrix1, size);

    printf("\nMatrix 2:\n");
    print_matrix(matrix2, size);

    int **result = add_matrices(matrix1, matrix2, size);

    printf("\nAddition of Matrix 1 and Matrix 2:\n");
    print_matrix(result, size);

    result = subtract_matrices(matrix1, matrix2, size);

    printf("\nSubtraction of Matrix 1 and Matrix 2:\n");
    print_matrix(result, size);

    result = multiply_matrices(matrix1, matrix2, size);

    printf("\nMultiplication of Matrix 1 and Matrix 2:\n");
    print_matrix(result, size);

    return 0;
}