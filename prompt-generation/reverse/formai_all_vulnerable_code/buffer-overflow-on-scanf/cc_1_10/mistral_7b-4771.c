//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void knapSack(int W, int n, Item items[]) {
    int K[n + 1][W + 1];
    int i, w;

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (items[i - 1].weight <= w)
                K[i][w] = max(K[i - 1][w], items[i - 1].value + K[i - 1][w - items[i - 1].weight]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    printf("Maximum value that can be put in a knapsack of capacity %d is %d\n", W, K[n][W]);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int i, n, W;
    Item items[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the details of %d items:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &items[i].id, &items[i].weight, &items[i].value);
    }

    knapSack(W, n, items);

    return 0;
}