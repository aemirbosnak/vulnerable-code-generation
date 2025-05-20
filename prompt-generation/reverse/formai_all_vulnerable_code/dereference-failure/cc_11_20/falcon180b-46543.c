//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, n, m;
    float x, y, z, a, b, c;
    char ch;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    float **matrix1 = (float **)malloc(m * sizeof(float *));
    for (i = 0; i < m; i++)
    {
        matrix1[i] = (float *)malloc(n * sizeof(float));
    }

    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &matrix1[i][j]);
        }
    }

    float **matrix2 = (float **)malloc(m * sizeof(float *));
    for (i = 0; i < m; i++)
    {
        matrix2[i] = (float *)malloc(n * sizeof(float));
    }

    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &matrix2[i][j]);
        }
    }

    float **sum = (float **)malloc(m * sizeof(float *));
    for (i = 0; i < m; i++)
    {
        sum[i] = (float *)malloc(n * sizeof(float));
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("The sum of matrices is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%f ", sum[i][j]);
        }
        printf("\n");
    }

    free(matrix1);
    free(matrix2);
    free(sum);

    return 0;
}