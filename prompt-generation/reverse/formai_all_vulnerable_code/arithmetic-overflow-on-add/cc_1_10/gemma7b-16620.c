//Gemma-7B DATASET v1.0 Category: Pattern printing ; Style: rigorous
#include <stdio.h>

int main()
{
    int n;
    scanf("Enter the number of rows: ", &n);

    // Calculate the number of columns based on the number of rows
    int m = n + 1;

    // Allocate memory for the matrix
    int **arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(m * sizeof(int));
    }

    // Initialize the matrix with the desired pattern
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0 || i == 0)
            {
                arr[i][j] = 1;
            }
            else if (i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }

    // Print the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the matrix
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}