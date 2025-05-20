//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &m, &n);

    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix before transposition:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int** transposedMatrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        transposedMatrix[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    printf("Matrix after transposition:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", transposedMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < n; i++)
    {
        free(transposedMatrix[i]);
    }
    free(transposedMatrix);

    return 0;
}