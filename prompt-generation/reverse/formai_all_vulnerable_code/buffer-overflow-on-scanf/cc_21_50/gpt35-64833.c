//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>

int main()
{
    printf("MATRIX OPERATIONS\n");
    printf("=================\n");

    int rowsA, colsA, rowsB, colsB;

    // Input size of matrix A
    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    // Declare matrix A and input its elements
    int matrixA[rowsA][colsA];
    printf("Enter elements of matrix A:\n");
    for(int i = 0; i < rowsA; i++)
    {
        for(int j = 0; j < colsA; j++)
        {
            printf("Row %d Column %d: ", i+1, j+1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Input size of matrix B
    printf("\nEnter rows and columns of matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    // Declare matrix B and input its elements
    int matrixB[rowsB][colsB];
    printf("Enter elements of matrix B:\n");
    for(int i = 0; i < rowsB; i++)
    {
        for(int j = 0; j < colsB; j++)
        {
            printf("Row %d Column %d: ", i+1, j+1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Display matrix A
    printf("\nMatrix A:\n");
    for(int i = 0; i < rowsA; i++)
    {
        for(int j = 0; j < colsA; j++)
        {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    // Display matrix B
    printf("\nMatrix B:\n");
    for(int i = 0; i < rowsB; i++)
    {
        for(int j = 0; j < colsB; j++)
        {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    // Check if matrices can be added
    if(rowsA == rowsB && colsA == colsB)
    {
        // Declare matrix C and add matrix A and B
        int matrixC[rowsA][colsA];
        for(int i = 0; i < rowsA; i++)
        {
            for(int j = 0; j < colsA; j++)
            {
                matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }

        // Display matrix C
        printf("\nMatrix C (A + B):\n");
        for(int i = 0; i < rowsA; i++)
        {
            for(int j = 0; j < colsA; j++)
            {
                printf("%d ", matrixC[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nCannot add matrices A and B.\n");
    }

    // Check if matrices can be multiplied
    if(colsA == rowsB)
    {
        // Declare matrix D and multiply matrix A and B
        int matrixD[rowsA][colsB];
        for(int i = 0; i < rowsA; i++)
        {
            for(int j = 0; j < colsB; j++)
            {
                matrixD[i][j] = 0;
                for(int k = 0; k < colsA; k++)
                {
                    matrixD[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }

        // Display matrix D
        printf("\nMatrix D (A * B):\n");
        for(int i = 0; i < rowsA; i++)
        {
            for(int j = 0; j < colsB; j++)
            {
                printf("%d ", matrixD[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nCannot multiply matrices A and B.\n");
    }

    return 0;
}