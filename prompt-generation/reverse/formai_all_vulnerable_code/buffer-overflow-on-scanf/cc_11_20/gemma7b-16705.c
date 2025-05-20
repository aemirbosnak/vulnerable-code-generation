//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int n, i, j, matrix[MAX][MAX], a[MAX], b[MAX], c[MAX];

    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &n, &i);

    matrix[n][i] = 1;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < i; i++)
        {
            matrix[j][i] = 0;
        }
    }

    printf("Enter the elements of the matrix: ");
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < i; i++)
        {
            scanf("%d", &matrix[j][i]);
        }
    }

    printf("The elements of the matrix are: ");
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < i; i++)
        {
            printf("%d ", matrix[j][i]);
        }
    }

    a[n] = 1;
    for (i = 0; i < n; i++)
    {
        a[i] = matrix[i][0];
    }

    b[n] = 1;
    for (i = 0; i < n; i++)
    {
        b[i] = matrix[0][i];
    }

    c[n] = 1;
    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
    }

    printf("The elements of the array c are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}