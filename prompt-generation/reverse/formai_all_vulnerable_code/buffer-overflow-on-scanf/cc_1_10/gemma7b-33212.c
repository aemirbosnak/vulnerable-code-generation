//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Allocate memory for the matrix
    int **a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    // Get the elements of the matrix
    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Print the matrix
    printf("The matrix is: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    printf("The transposed matrix is: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            k = a[j][i];
            a[j][i] = a[i][j];
            a[i][j] = k;
        }
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}