//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Percolation Simulation function
void percolat(int **arr, int n, int m)
{
    // Allocate memory for the array
    arr = (int *)malloc(n * m * sizeof(int));

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Randomly fill the array with 1s
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    // Percolate the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                // Check the four neighbors
                if (arr[i - 1][j] == 1)
                {
                    arr[i - 1][j] = 1;
                }
                if (arr[i + 1][j] == 1)
                {
                    arr[i + 1][j] = 1;
                }
                if (arr[i][j - 1] == 1)
                {
                    arr[i][j - 1] = 1;
                }
                if (arr[i][j + 1] == 1)
                {
                    arr[i][j + 1] = 1;
                }
            }
        }
    }

    // Print the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    percolat(NULL, n, m);

    return 0;
}