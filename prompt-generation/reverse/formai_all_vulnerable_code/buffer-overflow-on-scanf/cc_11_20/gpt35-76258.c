//FormAI DATASET v1.0 Category: Matrix operations ; Style: ephemeral
// Matrix Operations Example Program

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int rowsA, colsA, rowsB, colsB, i, j, k;
    float **A, **B, **C;

    // Get input from user
    printf("Enter number of rows and columns for Matrix A (separated by space): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter number of rows and columns for Matrix B (separated by space): ");
    scanf("%d %d", &rowsB, &colsB);

    // Check if matrix multiplication is possible
    if (colsA != rowsB)
    {
        printf("Matrix multiplication is not possible\n");
        exit(1);
    }

    // Allocate memory for matrices A, B, and C
    A = (float **)malloc(rowsA * sizeof(float *));
    B = (float **)malloc(rowsB * sizeof(float *));
    C = (float **)malloc(rowsA * sizeof(float *));
    for (i = 0; i < rowsA; i++)
    {
        A[i] = (float *)malloc(colsA * sizeof(float));
        C[i] = (float *)malloc(colsB * sizeof(float));
    }
    for (i = 0; i < rowsB; i++)
        B[i] = (float *)malloc(colsB * sizeof(float));

    // Input values for matrices A and B
    printf("Enter values for Matrix A:\n");
    for (i = 0; i < rowsA; i++)
        for (j = 0; j < colsA; j++)
            scanf("%f", &A[i][j]);

    printf("Enter values for Matrix B:\n");
    for (i = 0; i < rowsB; i++)
        for (j = 0; j < colsB; j++)
            scanf("%f", &B[i][j]);

    // Multiply matrices A and B
    for (i = 0; i < rowsA; i++)
    {
        for (j = 0; j < colsB; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < colsA; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    // Output resulting matrix C
    printf("\nResultant Matrix C:\n");
    for (i = 0; i < rowsA; i++)
    {
        for (j = 0; j < colsB; j++)
        {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory for matrices
    for (i = 0; i < rowsA; i++)
    {
        free(A[i]);
        free(C[i]);
    }
    for (i = 0; i < rowsB; i++)
        free(B[i]);
    free(A);
    free(B);
    free(C);

    return 0;
}