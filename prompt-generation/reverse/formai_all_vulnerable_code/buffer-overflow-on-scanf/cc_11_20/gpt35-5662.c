//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int m, n, i, j, k, sum = 0;
    printf("\n\nShocking Performance-Critical Component Example Program\n\n");
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int **a = (int **)malloc(m * sizeof(int *));
    for(i = 0; i < m; i++)
        a[i] = (int *)malloc(n * sizeof(int));

    int **b = (int **)malloc(m * sizeof(int *));
    for(i = 0; i < m; i++)
        b[i] = (int *)malloc(n * sizeof(int));

    int **c = (int **)malloc(m * sizeof(int *));
    for(i = 0; i < m; i++)
        c[i] = (int *)malloc(n * sizeof(int));

    printf("\nEnter the elements of the first array:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the elements of the second array:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nCalculating Shocking Performance-Critical Component....please wait...\n");
    printf("\n");

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for(k = 0; k < n; k++)
            {
                sum = sum + a[i][k] * b[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }

    printf("\nThe result of matrix multiplication is:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < m; i++)
        free(a[i]);
    free(a);

    for(i = 0; i < m; i++)
        free(b[i]);
    free(b);

    for(i = 0; i < m; i++)
        free(c[i]);
    free(c);
    printf("\n\nShocking Performance-Critical Component is Completed !!\n");
}