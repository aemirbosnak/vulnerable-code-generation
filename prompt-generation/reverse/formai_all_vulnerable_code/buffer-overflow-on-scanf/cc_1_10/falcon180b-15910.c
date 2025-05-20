//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

typedef struct {
    int value;
    int weight;
} item;

int compare(const void *a, const void *b) {
    item *item_a = (item *) a;
    item *item_b = (item *) b;

    if (item_a->value > item_b->value) {
        return -1;
    } else if (item_a->value == item_b->value) {
        if (item_a->weight < item_b->weight) {
            return -1;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}

void knapsack(item items[], int n, int capacity) {
    qsort(items, n, sizeof(item), compare);

    int knap_wt = 0;
    int knap_val = 0;

    for (int i = 0; i < n; i++) {
        if (knap_wt + items[i].weight <= capacity) {
            knap_wt += items[i].weight;
            knap_val += items[i].value;
        }
    }

    printf("Maximum value that can be obtained: %d\n", knap_val);
}

int main() {
    item items[MAX_ITEMS];
    int n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d:\n", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsack(items, n, capacity);

    return 0;
}