//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, a[100], b[100], c[100];
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

    int total_weight = 0, total_value = 0;
    for (i = 0; i < n; i++)
    {
        if (c[i] > 0)
        {
            total_weight += a[i] * c[i];
            total_value += b[i] * c[i];
        }
    }

    printf("The maximum value that can be obtained is: %d", total_value);
    printf("\nThe items that can be taken are: ");
    for (i = 0; i < n; i++)
    {
        if (c[i] > 0)
        {
            printf("%d ", a[i] * c[i]);
        }
    }

    return 0;
}