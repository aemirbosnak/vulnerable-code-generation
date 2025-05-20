//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, a[MAX], b[MAX], c[MAX];

    printf("Shocked Greedy Algorithms Example!\n");

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the values of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("Enter the total capacity of the bag: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        c[i] = b[i] / a[i];
    }

    j = 0;
    while (j < n && k > 0)
    {
        if (c[j] > 0)
        {
            k -= a[j];
            c[j]--;
        }
        else
        {
            j++;
        }
    }

    printf("The total value of the items that can be carried is: ");
    int totalValue = 0;
    for (i = 0; i < n; i++)
    {
        totalValue += b[i] * c[i];
    }
    printf("%d\n", totalValue);

    return 0;
}