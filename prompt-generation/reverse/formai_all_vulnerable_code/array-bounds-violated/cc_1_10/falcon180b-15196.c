//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX 1000
#define INF INT_MAX

int n, m, k;
int val[MAX], wt[MAX];
int dp[MAX][MAX];

void knapSack(int w, int i)
{
    if (i == 0 || w == 0)
        return;

    if (dp[i][w]!= -1)
        return;

    if (wt[i - 1] <= w)
        knapSack(w - wt[i - 1], i - 1);

    if (val[i - 1] + dp[i - 1][w] > val[i - 1] + dp[i - 1][w - wt[i - 1]])
        dp[i][w] = val[i - 1] + dp[i - 1][w];
    else
        dp[i][w] = val[i - 1] + dp[i - 1][w - wt[i - 1]];
}

void printSolution(int i, int j)
{
    if (i == 0)
        return;

    if (dp[i][j] == dp[i - 1][j])
        printSolution(i - 1, j);
    else
    {
        printf("Item %d is included\n", i);
        j -= wt[i - 1];
        printSolution(i - 1, j);
    }
}

int main()
{
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &k);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = -1;
        }
    }

    knapSack(k, n);

    printf("The maximum value that can be obtained is: %d\n", dp[n][k]);

    printSolution(n, k);

    return 0;
}