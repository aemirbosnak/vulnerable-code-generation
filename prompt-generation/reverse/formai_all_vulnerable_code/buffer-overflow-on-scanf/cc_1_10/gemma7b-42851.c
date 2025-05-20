//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, matrix_a[10][10], matrix_b[10][10], result[10][10];

    printf("Welcome to the mind-bending Matrix Operations Laboratory, Mr. Holmes.\n");

    printf("Please provide the number of rows and columns for the matrices:");
    scanf("%d %d", &n, &m);

    printf("Enter the elements of the first matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matrix_a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matrix_b[i][j]);
        }
    }

    k = n;
    l = m;

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < l; j++)
        {
            result[i][j] = 0;
            for (int h = 0; h < m; h++)
            {
                result[i][j] += matrix_a[i][h] * matrix_b[h][j];
            }
        }
    }

    printf("Behold, Mr. Holmes, the product of the two matrices:**\n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < l; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}