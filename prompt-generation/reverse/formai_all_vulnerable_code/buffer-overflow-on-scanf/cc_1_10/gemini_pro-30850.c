//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare_items(const void *a, const void *b) {
    const Item *ia = (const Item *)a;
    const Item *ib = (const Item *)b;

    return (ia->value / ia->weight) - (ib->value / ib->weight);
}

int main() {
    int n, capacity;
    Item *items;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    items = (Item *)malloc(sizeof(Item) * n);

    for (int i = 0; i < n; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);

        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &items[i].value);
    }

    qsort(items, n, sizeof(Item), compare_items);

    int total_weight = 0;
    int total_value = 0;

    for (int i = 0; i < n; i++) {
        if (total_weight + items[i].weight <= capacity) {
            total_weight += items[i].weight;
            total_value += items[i].value;
        }
    }

    printf("Total weight: %d\n", total_weight);
    printf("Total value: %d\n", total_value);

    return 0;
}