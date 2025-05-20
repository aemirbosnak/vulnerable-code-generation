//FormAI DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int i, j, k; // Loop variables
    int m, n, p, q; // Matrix dimensions

    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d%d", &m, &n);
    printf("Enter the elements of matrix A:\n");
    
    // Input matrix A
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d%d", &p, &q);
    printf("Enter the elements of matrix B:\n");

    // Input matrix B
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Check for validity of multiplication
    if (n != p)
    {
        printf("The multiplication of A and B is not possible!\n");
        return 0;
    }
    
    // Perform matrix multiplication
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < p; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Output resultant matrix
    printf("The resultant matrix C = A x B is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}