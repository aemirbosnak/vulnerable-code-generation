//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // define the matrix size
    int size = 5;

    // allocate memory for the matrix
    int *matrix = (int *)malloc(size * size * sizeof(int));

    // initialize the matrix with random values
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrix[i * size + j] = rand() % 10;
        }
    }

    // perform matrix operations
    printf("Original Matrix:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i * size + j]);
        }
        printf("\n");
    }

    // transpose the matrix
    int transposed[size][size];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            transposed[j][i] = matrix[i * size + j];
        }
    }

    // print the transposed matrix
    printf("Transposed Matrix:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    // multiply two matrices
    int *product = (int *)malloc(size * size * sizeof(int));
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            int sum = 0;
            for(int k = 0; k < size; k++)
            {
                sum += matrix[i * size + k] * transposed[k][j];
            }
            product[i * size + j] = sum;
        }
    }

    // print the product matrix
    printf("Product Matrix:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", product[i * size + j]);
        }
        printf("\n");
    }

    // free the memory
    free(matrix);
    free(transposed);
    free(product);

    return 0;
}