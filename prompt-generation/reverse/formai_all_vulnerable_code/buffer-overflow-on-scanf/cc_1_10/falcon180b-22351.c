//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100

void knapSack(int W, int wt[], int val[], int n, int K[], int i) {
    if (i == n || W == 0)
        return;

    if (W >= wt[i]) {
        K[i] = val[i];
        knapSack(W - wt[i], wt, val, n, K, i + 1);
    }

    knapSack(W, wt, val, n, K, i + 1);
}

void printSolution(int n, int K[]) {
    printf("The following items are included in the knapsack:\n");
    for (int i = 0; i < n; i++) {
        if (K[i]!= 0)
            printf("%d ", i + 1);
    }
}

int main() {
    int n, W, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];
    printf("Enter the weight and value of each item:\n");

    for (i = 0; i < n; i++) {
        printf("For item %d:\n", i + 1);
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("Enter the weight capacity of the knapsack: ");
    scanf("%d", &W);

    int K[n];
    knapSack(W, wt, val, n, K, 0);

    printf("\nThe maximum value that can be obtained is: %d\n", K[0]);

    printf("\nThe items included in the knapsack are:\n");
    printSolution(n, K);

    return 0;
}