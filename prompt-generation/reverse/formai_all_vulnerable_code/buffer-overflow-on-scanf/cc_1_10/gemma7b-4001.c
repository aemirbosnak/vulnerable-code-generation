//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, greed, total = 0;
    scanf("Enter the number of items: ", &n);

    int item_values[n];
    printf("Enter the item values: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d ", &item_values[i]);
    }

    printf("Enter the number of bags: ");
    scanf("%d ", &k);

    int bag_sizes[k];
    printf("Enter the bag sizes: ");
    for (i = 0; i < k; i++)
    {
        scanf("%d ", &bag_sizes[i]);
    }

    greed = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (item_values[i] <= bag_sizes[j])
            {
                bag_sizes[j] -= item_values[i];
                greed++;
            }
        }
    }

    total = 0;
    for (i = 0; i < k; i++)
    {
        total += bag_sizes[i];
    }

    printf("The total weight of items that can be carried is: %d", total);

    return 0;
}