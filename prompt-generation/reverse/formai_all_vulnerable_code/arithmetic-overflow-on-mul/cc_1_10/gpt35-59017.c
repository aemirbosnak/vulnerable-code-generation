//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: optimized
#include <stdio.h>

#define MAX 1000

// function to implement the greedy approach
void Greedy(int n, int W, int weight[], int profits[])
{
    int i, j[MAX], maxprofit = 0;

    for (i = 0; i < n; i++)
    {
        j[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] > W)
            break;
        else
        {
            j[i] = 1;
            maxprofit += profits[i];
            W -= weight[i];
        }
    }

    if (i < n)
        j[i] = W / weight[i];

    maxprofit += j[i] * profits[i];

    printf("\n The solution vector is: ");
    for (i = 0; i < n; i++)
        printf("%d ", j[i]);

    printf("\n Maximum profit = %d", maxprofit);
}

// driver function to test the greedy approach
int main()
{
    int n, W, i, weight[MAX], profits[MAX];

    printf("\n Enter the number of items: ");
    scanf("%d", &n);

    printf("\n Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    printf("\n Enter the weights of the items: ");
    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("\n Enter the profits of the items: ");
    for (i = 0; i < n; i++)
        scanf("%d", &profits[i]);

    Greedy(n, W, weight, profits);
    return 0;
}