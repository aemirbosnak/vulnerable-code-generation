//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void main()
{
    int n, i, j, k, a[MAX], greed[MAX];
    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Enter the number of thieves: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        greed[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (greed[j] < a[i])
            {
                greed[j] = a[i];
            }
        }
    }

    printf("The greedy thieves have stolen the following items: ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", greed[i]);
    }

    printf("\nTotal stolen items: %d", sum(greed, k));

    return;
}

int sum(int *arr, int n)
{
    int i, total = 0;
    for (i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return total;
}