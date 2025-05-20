//Code Llama-13B DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
/*
 * A Greedy Algorithm example program in an invasive style
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    int value;
    int weight;
};

int compare_items(const void *a, const void *b) {
    struct item *item_a = (struct item *)a;
    struct item *item_b = (struct item *)b;

    return item_b->value - item_a->value;
}

int main() {
    int capacity;
    int n_items;
    struct item items[MAX_ITEMS];

    // read input
    scanf("%d %d", &capacity, &n_items);
    for (int i = 0; i < n_items; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // sort items by value
    qsort(items, n_items, sizeof(struct item), compare_items);

    int total_value = 0;
    int total_weight = 0;

    for (int i = 0; i < n_items; i++) {
        if (total_weight + items[i].weight <= capacity) {
            total_value += items[i].value;
            total_weight += items[i].weight;
        }
    }

    printf("Total value: %d\n", total_value);
    printf("Total weight: %d\n", total_weight);

    return 0;
}