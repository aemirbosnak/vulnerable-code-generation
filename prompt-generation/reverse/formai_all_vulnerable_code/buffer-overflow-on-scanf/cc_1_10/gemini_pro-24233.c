//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

typedef struct {
    int weight;
    int value;
} Item;

int compare_items(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return item2->value / item2->weight - item1->value / item1->weight;
}

int knapsack(Item items[], int n, int W) {
    // Sort items in decreasing order of value per weight
    qsort(items, n, sizeof(Item), compare_items);

    int total_weight = 0;
    int total_value = 0;
    for (int i = 0; i < n; i++) {
        int remaining_weight = W - total_weight;
        if (items[i].weight <= remaining_weight) {
            total_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            // If the item doesn't fit, add a fraction of it to the knapsack
            double fraction = (double)remaining_weight / items[i].weight;
            total_weight += fraction * items[i].weight;
            total_value += fraction * items[i].value;
            break;
        }
    }

    return total_value;
}

int main() {
    // Initialize items
    Item items[] = {
        {2, 10},
        {5, 20},
        {3, 15},
        {4, 18},
        {1, 5}
    };
    int n = sizeof(items) / sizeof(items[0]);

    // Get knapsack weight from user
    int W;
    printf("Enter knapsack weight: ");
    scanf("%d", &W);

    // Solve knapsack problem
    int max_value = knapsack(items, n, W);

    // Print the result
    printf("Maximum value: %d\n", max_value);

    return 0;
}