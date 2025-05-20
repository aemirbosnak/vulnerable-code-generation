//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm()
{
    int n, i, j, total = 0, selected = 0;
    int arr[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the total weight of the bag: ");
    scanf("%d", &total);

    for (i = 0; i < n; i++)
    {
        if (selected == total)
        {
            break;
        }
        if (arr[i] <= total - selected)
        {
            selected += arr[i];
            total -= arr[i];
            printf("Item %d is selected.\n", i + 1);
        }
    }

    if (selected != total)
    {
        printf("The bag is not full.");
    }
    else
    {
        printf("The bag is full.");
    }
}

int main()
{
    greedy_algorithm();

    return 0;
}