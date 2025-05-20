//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_W 10000

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void knapSack(int W, Item items[], int n) {
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (items[i - 1].weight <= w)
                K[i][w] = max(K[i - 1][w], items[i - 1].value + K[i - 1][w - items[i - 1].weight]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int index = n;
    int weight = W;
    int value = 0;

    while (index > 0 && weight > 0) {
        if (K[index - 1][weight] < K[index][weight - items[index - 1].weight]) {
            value += K[index][weight - items[index - 1].weight] - K[index - 1][weight];
            weight -= items[index - 1].weight;
            index--;
        } else {
            index--;
        }
    }

    printf("The maximum value is %d\n", value);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter %d items:\n", n);

    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d%d", &items[i].weight, &items[i].value);
        items[i].id = i + 1;
    }

    knapSack(W, items, n);

    return 0;
}