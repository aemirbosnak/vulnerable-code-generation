//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, greedy_algorithm(int **arr, int n);
    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &arr[i][0]);
        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &arr[i][1]);
    }

    k = greedy_algorithm(arr, n);

    printf("The total value of items taken is: %d", k);

    return 0;
}

int greedy_algorithm(int **arr, int n)
{
    int i, j, total_value = 0, current_weight = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_weight; j++)
        {
            if (arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1])
            {
                current_weight = arr[i][0];
                total_value = arr[i][1];
            }
        }
        current_weight += arr[i][0];
    }

    return total_value;
}