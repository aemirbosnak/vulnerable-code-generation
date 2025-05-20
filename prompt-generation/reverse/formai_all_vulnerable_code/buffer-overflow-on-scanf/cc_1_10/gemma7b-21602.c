//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_algorithm()
{
    int i, j, n, total_weight = 0, current_weight = 0, maximum_weight = 0;
    int items[MAX], weights[MAX], values[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the item weight: ");
        scanf("%d", &weights[i]);

        printf("Enter the item value: ");
        scanf("%d", &values[i]);
    }

    printf("Enter the maximum weight of the bag: ");
    scanf("%d", &maximum_weight);

    for (i = 0; i < n; i++)
    {
        items[i] = values[i] / weights[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_weight; j++)
        {
            if (items[i] > items[j])
            {
                current_weight++;
                total_weight += weights[i];
                items[i] = 0;
                break;
            }
        }
    }

    printf("The total weight is: %d", total_weight);
    printf("\nThe total value is: %d", total_weight * maximum_weight);
}

int main()
{
    greedy_algorithm();

    return 0;
}