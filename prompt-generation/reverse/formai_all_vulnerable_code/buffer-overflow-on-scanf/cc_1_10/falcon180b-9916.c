//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_VALUE 1000

typedef struct {
    int value;
    int weight;
} Item;

int compare(const void* a, const void* b) {
    const Item* itemA = (const Item*)a;
    const Item* itemB = (const Item*)b;

    if (itemA->value > itemB->value) {
        return 1;
    } else if (itemA->value < itemB->value) {
        return -1;
    } else {
        return 0;
    }
}

void knapSack(Item items[], int n, int W) {
    int i, j;
    int value[n];
    int weight[n];
    int k = 0;

    for (i = 0; i < n; i++) {
        value[i] = items[i].value;
        weight[i] = items[i].weight;
    }

    qsort(value, n, sizeof(int), compare);
    qsort(weight, n, sizeof(int), compare);

    for (i = 0, j = 0; i < n; i++) {
        if (weight[i] <= W) {
            W -= weight[i];
            k += value[i];
        }
    }

    printf("Maximum value: %d\n", k);
}

int main() {
    int n, W;
    Item items[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i+1);
        printf("Value: ");
        scanf("%d", &items[i].value);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
    }

    printf("Enter the maximum weight: ");
    scanf("%d", &W);

    knapSack(items, n, W);

    return 0;
}