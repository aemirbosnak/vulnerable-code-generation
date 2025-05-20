//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void main()
{
    int n, i, j, k, a[MAX], b[MAX], c[MAX], total = 0, my_share = 0;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the number of players: ");
    scanf("%d", &n);

    printf("Enter the total number of items: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the share of player %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    for (i = 0; i < k; i++)
    {
        c[i] = a[i] * b[i] / total;
    }

    printf("Here is the distribution of items:\n");

    for (i = 0; i < k; i++)
    {
        printf("Item %d: %d\n", i + 1, c[i]);
    }

    printf("Your share is: %d\n", c[k]);

    my_share = c[k] * 100 / total;

    printf("Your share is %d%% of the total.\n", my_share);

    return;
}