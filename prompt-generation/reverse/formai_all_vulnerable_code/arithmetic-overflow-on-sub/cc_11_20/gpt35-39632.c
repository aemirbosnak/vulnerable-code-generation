//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

#define MATRIX_SIZE 20

int main()
{
    float matrix[MATRIX_SIZE][MATRIX_SIZE], result[MATRIX_SIZE];
    int n, i, j, k;

    printf("Enter the order of the matrix (must be less than or equal to %d): ", MATRIX_SIZE);
    scanf("%d", &n);

    // Taking Input Matrix
    printf("Enter the elements of the matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Taking Input Column Vector
    printf("Enter the elements of the column vector:\n");
    for(i=0; i<n; i++)
    {
        scanf("%f", &result[i]);
    }

    // Gaussian Elimination Algorithm
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i>j)
            {
                float factor = matrix[i][j]/matrix[j][j];
                for(k=0; k<n; k++)
                {
                    matrix[i][k] -= factor * matrix[j][k];
                }
                result[i] -= factor * result[j];
            }
        }
    }

    // Backward Substitution
    for(i=n-1; i>=0; i--)
    {
        float sum = 0;
        for(j=i+1; j<n; j++)
        {
            sum += matrix[i][j] * result[j];
        }
        result[i] = (result[i] - sum)/matrix[i][i];
    }

    // Printing Solution
    printf("\nThe solution of the given system of linear equations is:\n");
    for(i=0; i<n; i++)
    {
        printf("x%d = %f\n", i+1, result[i]);
    }

    return 0;
}