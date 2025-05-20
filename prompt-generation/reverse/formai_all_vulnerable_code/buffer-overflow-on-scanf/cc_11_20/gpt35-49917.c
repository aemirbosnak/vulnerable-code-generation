//FormAI DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, i, j, determinant = 0;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the matrix: \n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix is: \n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Find the determinant of the matrix
    if (m == n)
    {
        for (i = 0; i < m; i++)
        {
            int a = i;
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    determinant += matrix[i][j];
                }
                else
                {
                    determinant += (matrix[i][j] * a);
                    a--;
                }
            }
        }

        printf("The determinant of the matrix is: %d\n", determinant);
    }
    else
    {
        printf("The matrix is not square, it does not have a determinant.\n");
    }

    // Transpose the matrix
    printf("The transpose of the matrix is: \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    // Multiply the matrix by a scalar
    int scalar;
    printf("Enter a scalar value to multiply the matrix by: ");
    scanf("%d", &scalar);

    printf("The matrix multiplied by %d is: \n", scalar);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j] * scalar);
        }
        printf("\n");
    }

    printf("Thanks for using this program!\n");

    // Free the dynamically allocated memory
    for (i = 0; i < m; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}