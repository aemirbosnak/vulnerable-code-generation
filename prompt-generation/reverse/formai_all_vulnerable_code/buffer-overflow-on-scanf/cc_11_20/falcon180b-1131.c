//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int main()
{
    int m, n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    int **A = (int **)malloc(m * sizeof(int *));
    for(i=0; i<m; i++)
         A[i] = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of matrix A:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int **B = (int **)malloc(m * sizeof(int *));
    for(i=0; i<m; i++)
         B[i] = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of matrix B:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    int **C = (int **)malloc(m * sizeof(int *));
    for(i=0; i<m; i++)
         C[i] = (int *)malloc(n * sizeof(int));

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("The sum of matrices A and B is:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<m; i++)
         free(A[i]);
    free(A);

    for(i=0; i<m; i++)
         free(B[i]);
    free(B);

    for(i=0; i<m; i++)
         free(C[i]);
    free(C);

    return 0;
}