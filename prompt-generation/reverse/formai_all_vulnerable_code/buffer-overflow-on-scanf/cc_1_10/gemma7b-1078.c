//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL;
    int r, c, i, j, k, l;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    a = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
    {
        a[i] = (int *)malloc(c * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The elements of the matrix are: ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
    }

    printf("\n");

    // Transpose the matrix
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            k = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = k;
        }
    }

    printf("The transposed matrix is: ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
    }

    return 0;
}