//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int r = 0, c1 = 0, c2 = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &c1);

    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &c2);

    a = (int **)malloc(r * sizeof(int *));
    b = (int **)malloc(r * sizeof(int *));
    c = (int **)malloc(r * sizeof(int *));

    for (int i = 0; i < r; i++)
    {
        a[i] = (int *)malloc(c1 * sizeof(int));
        b[i] = (int *)malloc(c2 * sizeof(int));
        c[i] = (int *)malloc(c2 * sizeof(int));
    }

    // Matrix A input
    printf("Enter the elements of the first matrix: ");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Matrix B input
    printf("Enter the elements of the second matrix: ");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix C calculation
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Matrix C output
    printf("The elements of the resulting matrix are: ");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}