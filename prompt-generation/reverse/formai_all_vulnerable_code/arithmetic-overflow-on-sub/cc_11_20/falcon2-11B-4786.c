//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main()
{
    int i, j, k, n, m, count = 0;
    int matrix[MAX_ROWS][MAX_COLS];
    int maxRow, maxCol;

    printf("Enter the number of rows and columns for the matrix:\n");
    scanf("%d %d", &n, &m);
    maxRow = n;
    maxCol = m;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter the element in %d row and %d column:\n", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
            count++;
        }
    }

    printf("\nMatrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the row number for the transpose matrix:\n");
    scanf("%d", &k);
    k--;

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < m; j++)
        {
            matrix[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose Matrix:\n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    printf("\nEnter the row number for the reverse transpose matrix:\n");
    scanf("%d", &k);
    k--;

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < m; j++)
        {
            matrix[m - 1 - j][i] = matrix[j][i];
        }
    }

    printf("\nReverse Transpose Matrix:\n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    printf("\nEnter the row number for the multiplication matrix:\n");
    scanf("%d", &k);
    k--;

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (n = 0; n < m; n++)
            {
                matrix[i][j] += matrix[i][n] * matrix[n][j];
            }
        }
    }

    printf("\nMultiplication Matrix:\n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}