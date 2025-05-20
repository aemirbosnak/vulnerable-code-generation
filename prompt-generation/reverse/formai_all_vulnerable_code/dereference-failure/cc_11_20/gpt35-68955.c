//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols, i, j;
    
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &rows, &cols);
    
    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));
    
    // Initialize the matrix with random values
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            matrix[i][j] = rand() % 10;
    
    printf("Original matrix:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    
    // Transpose the matrix
    int **transpose = (int **)malloc(cols * sizeof(int *));
    for(i = 0; i < cols; i++)
        transpose[i] = (int *)malloc(rows * sizeof(int));

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            transpose[j][i] = matrix[i][j];
    
    printf("Transpose of matrix:\n");
    for(i = 0; i < cols; i++)
    {
        for(j = 0; j < rows; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }
    
    // Compute the product of the matrix and its transpose
    int **product = (int **)malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++)
        product[i] = (int *)malloc(rows * sizeof(int));
    
    for(i = 0; i < rows; i++)
        for(j = 0; j < rows; j++)
            product[i][j] = 0;

    for(i = 0; i < rows; i++)
        for(j = 0; j < rows; j++)
            for(int k = 0; k < cols; k++)
                product[i][j] += matrix[i][k] * transpose[k][j];
    
    printf("Product of matrix and its transpose:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < rows; j++)
            printf("%d ", product[i][j]);
        printf("\n");
    }
    
    // Free the dynamically allocated memory
    for(i = 0; i < rows; i++)
    {
        free(matrix[i]);
        free(transpose[i]);
        free(product[i]);
    }
    free(matrix);
    free(transpose);
    free(product);
    
    return 0;
}