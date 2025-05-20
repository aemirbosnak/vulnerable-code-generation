//FormAI DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Futuristic Matrix Operations Program

int main()
{
    int rows, cols, i, j;
    printf("Enter number of rows in matrix: ");
    scanf("%d", &rows);
    printf("Enter number of columns in matrix: ");
    scanf("%d", &cols);

    // create matrix A
    int **A = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        A[i] = (int *)malloc(cols * sizeof(int));
    }

    // initialize matrix A
    printf("\nEnter matrix A elements:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // create matrix B
    int **B = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        B[i] = (int *)malloc(cols * sizeof(int));
    }

    // initialize matrix B
    printf("\nEnter matrix B elements:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

   // add matrix A and B
    int **C = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        C[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // print matrix C
    printf("\nMatrix C (A + B):\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // transpose matrix C
    printf("\nTranspose of matrix C:\n");
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            printf("%d ", C[j][i]);
        }
        printf("\n");
    }

    // free memory
    for (i = 0; i < rows; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}