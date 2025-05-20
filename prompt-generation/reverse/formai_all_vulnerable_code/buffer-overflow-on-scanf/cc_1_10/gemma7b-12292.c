//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, i, j, k, total = 0, greed_algo(int n, int **arr);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int **arr = (int *)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the item values and weights: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    k = greed_algo(n, arr);

    printf("The total weight is: %d", k);

    free(arr);
    return 0;
}

int greed_algo(int n, int **arr)
{
    int i, total = 0, w_total = 0, item_value_ratio[n];

    for(i = 0; i < n; i++)
    {
        item_value_ratio[i] = (arr[i][0] / arr[i][1]) * arr[i][1];
    }

    for(i = 0; i < n; i++)
    {
        if(w_total + arr[i][1] <= total)
        {
            w_total += arr[i][1];
            total += item_value_ratio[i];
        }
    }

    return total;
}