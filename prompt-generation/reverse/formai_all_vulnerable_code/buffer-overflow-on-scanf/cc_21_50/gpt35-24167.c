//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, m, choice;
    printf("Enter the number of rows and columns of matrix: ");
    scanf("%d %d", &n, &m);

    int A[n][m], B[n][m], C[n][m];

    while (1)
    {
        printf("\nSelect an operation\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the elements of matrix A:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%d", &A[i][j]);
                }
            }
            printf("\nEnter the elements of matrix B:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%d", &B[i][j]);
                    C[i][j] = A[i][j] + B[i][j];
                }
            }
            printf("\nMatrix A + B = \n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            printf("\nEnter the elements of matrix A:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%d", &A[i][j]);
                }
            }
            printf("\nEnter the elements of matrix B:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%d", &B[i][j]);
                    C[i][j] = A[i][j] - B[i][j];
                }
            }
            printf("\nMatrix A - B = \n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            printf("\nEnter the elements of matrix A:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%d", &A[i][j]);
                }
            }
            printf("\nEnter the elements of matrix B:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%d", &B[i][j]);
                }
            }
            printf("\nMatrix A * B = \n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    C[i][j] = 0;
                    for (int k = 0; k < m; k++)
                    {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
            break;
        case 4:
            printf("\nEnter the elements of matrix A:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%d", &A[i][j]);
                }
            }
            printf("\nTranspose of matrix A = \n");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    C[i][j] = A[j][i];
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid input!\n");
        }
    }
    return 0;
}