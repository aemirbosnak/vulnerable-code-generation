//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{
    int m, n, i, j;
    int **matrix;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    matrix = (int **) malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        matrix[i] = (int *) malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The entered matrix is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum += matrix[i][j];
        }
    }

    printf("The sum of all elements in the matrix is: %d\n", sum);

    int prod = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            prod *= matrix[i][j];
        }
    }

    printf("The product of all elements in the matrix is: %d\n", prod);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrix[i][j] = matrix[i][j] + 10;
        }
    }

    printf("The matrix with all elements increased by 10 is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}