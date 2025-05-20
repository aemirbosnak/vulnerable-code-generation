//FormAI DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>

// Function to add two matrices of size n x m
void add_matrices(int n, int m, int matrix1[n][m], int matrix2[n][m])
{
    int result[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nResult after addition:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices of size n x m and m x p
void multiply_matrices(int n, int m, int p, int matrix1[n][m], int matrix2[m][p])
{
    int result[n][p];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nResult after multiplication:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m, p;

    // Get input from user for the size of matrices
    printf("Enter the size of matrix A: (n x m)");
    scanf("%d %d", &n, &m);

    printf("Enter the size of matrix B: (m x p)");
    scanf("%d %d", &m, &p);

    // Create matrices A and B of the given sizes
    int matrix_A[n][m], matrix_B[m][p];

    // Get input from user for matrix A
    printf("\nEnter matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix_A[i][j]);
        }
    }

    // Get input from user for matrix B
    printf("\nEnter matrix B:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            scanf("%d", &matrix_B[i][j]);
        }
    }

    // Perform matrix operations
    add_matrices(n, m, matrix_A, matrix_B);
    multiply_matrices(n, m, p, matrix_A, matrix_B);

    return 0;
}