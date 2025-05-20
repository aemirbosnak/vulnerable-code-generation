//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

#define MAX 10000

int n, m;
int val[MAX], wt[MAX];
int W = 50;

void knapSack(int W, int wt[], int val[], int n, int V[], int i)
{
    if (n == 0 || W == 0)
        return;
    if (i == m)
        return;

    if (wt[i] <= W)
    {
        V[n++] = i;
        knapSack(W - wt[i], wt, val, n, V, i + 1);
    }
    else
        knapSack(W, wt, val, n, V, i + 1);
}

int main()
{
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight and value of each item:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &wt[i], &val[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int V[n];

    knapSack(W, wt, val, 0, V, 0);

    printf("The items selected are: ");

    for (int i = 0; i < n; i++)
    {
        if (V[i]!= 0)
            printf("%d ", V[i] + 1);
    }

    return 0;
}