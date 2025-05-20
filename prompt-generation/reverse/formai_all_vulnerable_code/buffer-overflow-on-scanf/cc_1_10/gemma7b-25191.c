//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, i, j, k, max_sum = 0, current_sum = 0;
    int **arr = NULL;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the weights and values for each item: ");
    for (i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for (i = 0; i < n; i++)
    {
        current_sum = 0;
        for (j = 0; j < MAX; j++)
        {
            current_sum = 0;
            for (k = 0; k < n; k++)
            {
                if (arr[k][0] <= j && current_sum < max_sum)
                {
                    current_sum += arr[k][1] * arr[k][0];
                }
            }
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
            }
        }
    }

    printf("The maximum sum is: %d", max_sum);

    free(arr);

    return 0;
}