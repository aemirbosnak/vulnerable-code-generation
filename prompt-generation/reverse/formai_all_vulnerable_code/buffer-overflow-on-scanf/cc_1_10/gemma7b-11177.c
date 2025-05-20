//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm()
{
    int n, i, j, total = 0, selected = 0;
    int arr[MAX], heap[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the capacities of each bag: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < total; j++)
        {
            if (arr[i] + heap[j] <= total)
            {
                selected++;
                heap[j] += arr[i];
                break;
            }
        }

        if (selected == 0)
        {
            total += arr[i];
        }
    }

    printf("The total weight of the selected items is: %d", total);
    printf("\nThe number of selected items is: %d", selected);
}

int main()
{
    greedy_algorithm();

    return 0;
}