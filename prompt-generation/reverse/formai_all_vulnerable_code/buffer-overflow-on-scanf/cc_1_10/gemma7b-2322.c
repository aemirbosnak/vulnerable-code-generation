//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, j, n, a[MAX], b[MAX], c[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights and values of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }

    // Calculate the total weight and value
    int totalWeight = 0, totalValue = 0;
    for (i = 0; i < n; i++)
    {
        totalWeight += a[i];
        totalValue += b[i];
    }

    // Calculate the maximum capacity of the bag
    int capacity = 0;
    printf("Enter the capacity of the bag: ");
    scanf("%d", &capacity);

    // Greedy algorithm
    int remainingCapacity = capacity;
    for (i = 0; i < n; i++)
    {
        // Calculate the ratio of value to weight
        double ratio = (double)b[i] / a[i];

        // If the ratio is greater than the current ratio, update the current ratio and the item index
        if (ratio > c[i])
        {
            c[i] = ratio;
        }
    }

    // Print the items that will be included in the bag
    printf("The items that will be included in the bag are: ");
    for (i = 0; i < n; i++)
    {
        if (c[i] > 0)
        {
            printf("%d ", i);
        }
    }

    printf("\nTotal value of items included: %d", totalValue);

    return 0;
}