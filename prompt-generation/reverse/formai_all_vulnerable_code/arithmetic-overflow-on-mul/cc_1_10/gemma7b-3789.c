//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algo(int **arr, int n)
{
    int i = 0;
    int j = 0;
    int total = 0;
    int current_size = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_size; j++)
        {
            if (arr[i][j] > total)
            {
                total = arr[i][j];
            }
        }

        current_size++;
        total += arr[i][current_size - 1];
    }

    printf("Total: %d", total);
}

int main()
{
    int n;
    scanf("Enter the number of items: ", &n);

    int **arr = (int *)malloc(n * MAX * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        scanf("Enter the weights and values for item %d: ", arr[i], arr[i] + MAX);
    }

    greedy_algo(arr, n);

    return 0;
}