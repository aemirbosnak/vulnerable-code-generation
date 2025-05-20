//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    int id;
    int value;
    int weight;
} Item;

int cmpfunc(const void *a, const void *b) {
    Item *x = (Item *)a;
    Item *y = (Item *)b;

    double r = (double)x->value / x->weight;
    double s = (double)y->value / y->weight;

    if (r > s)
        return -1;
    if (r < s)
        return 1;
    return 0;
}

int main() {
    int n, W;
    scanf("%d %d", &n, &W);

    Item *items = (Item *)calloc(n, sizeof(Item));

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].id, &items[i].value);
        items[i].weight = items[i].value / 3; // arbitrary weight calculation
    }

    qsort(items, n, sizeof(Item), cmpfunc);

    int includedItems = 0;
    int knapsackWeight = 0;

    for (int i = 0; i < n && knapsackWeight < W; i++) {
        if (items[i].weight <= W - knapsackWeight) {
            knapsackWeight += items[i].weight;
            printf("Item %d with value %d and weight %d included\n", items[i].id, items[i].value, items[i].weight);
            includedItems++;
        }
    }

    printf("Total value in the knapsack: %d\n", includedItems * items[0].value);

    free(items);

    return 0;
}