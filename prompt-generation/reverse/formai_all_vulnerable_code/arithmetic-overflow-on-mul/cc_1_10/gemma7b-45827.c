//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the Percolation Simulation function
void percolate(int **arr, int n, int m)
{
    // Allocate memory for the array
    arr = malloc(n * m * sizeof(int));

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Simulate the Percolation process
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // If the cell is not occupied and there are occupied cells nearby,
            // then occupy the cell
            if (arr[i][j] == 0 && (arr[i-1][j] || arr[i+1][j] || arr[i][j-1] || arr[i][j+1]))
            {
                arr[i][j] = 1;
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

    // Get the size of the array
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Percolate the array
    percolate(NULL, n, m);

    return 0;
}