//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int **arr = (int **)malloc(MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Percolation simulation
    int x = 0, y = 0, n = 0;
    while (1)
    {
        printf("Enter x, y, and n: ");
        scanf("%d %d %d", &x, &y, &n);

        if (x == -1 && y == -1 && n == -1)
            break;

        for (int i = 0; i < n; i++)
        {
            arr[x][y] = 1;
            x++;
            y++;
        }
    }

    // Display the result
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}