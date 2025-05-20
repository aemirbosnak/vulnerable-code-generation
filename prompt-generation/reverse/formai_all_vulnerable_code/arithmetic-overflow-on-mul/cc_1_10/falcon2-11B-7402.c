//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    // Create a matrix
    int n = 3;
    int m = 4;
    int matrix[n][m];

    // Populate the matrix with random values
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matrix[i][j] = (rand() % 100) + 1;
        }
    }

    // Print the matrix
    printf("Matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Perform matrix multiplication
    int product[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int sum = 0;
            for(int k = 0; k < m; k++)
            {
                sum += matrix[i][k] * matrix[k][j];
            }
            product[i][j] = sum;
        }
    }

    // Print the product matrix
    printf("\nProduct matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}