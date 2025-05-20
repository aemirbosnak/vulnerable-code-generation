//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("Enter the dimensions of the matrix (a, b): ");
    scanf("%d %d", &a, &b);

    // Allocate memory for the matrix
    int **matrix = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        matrix[i] = (int *)malloc(b * sizeof(int));
    }

    // Get the elements of the matrix
    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d ", &matrix[i][j]);
        }
    }

    // Transpose the matrix
    c = b;
    b = a;
    int **transpose = (int **)malloc(b * sizeof(int *));
    for (int i = 0; i < b; i++)
    {
        transpose[i] = (int *)malloc(c * sizeof(int));
    }

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }

    // Print the transposed matrix
    printf("The transposed matrix is: ");
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the matrix and transpose
    for (int i = 0; i < a; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < b; i++)
    {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}