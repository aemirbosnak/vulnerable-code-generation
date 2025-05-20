//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item1->value / item1->weight) - (item2->value / item2->weight);
}

int main() {
    Item items[MAX_ITEMS];
    int num_items, knapsack_weight;

    // Get the number of items and the knapsack weight.
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the knapsack weight: ");
    scanf("%d", &knapsack_weight);

    // Get the weight and value of each item.
    for (int i = 0; i < num_items; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &items[i].value);
    }

    // Sort the items in decreasing order of value per weight.
    qsort(items, num_items, sizeof(Item), compare);

    // Fill the knapsack with the items.
    int knapsack_weight_remaining = knapsack_weight;
    int knapsack_value = 0;
    for (int i = 0; i < num_items; i++) {
        if (items[i].weight <= knapsack_weight_remaining) {
            knapsack_weight_remaining -= items[i].weight;
            knapsack_value += items[i].value;
        } else {
            // The item is too heavy, so we add only a fraction of it to the knapsack.
            knapsack_value += (knapsack_weight_remaining * items[i].value) / items[i].weight;
            break;
        }
    }

    // Print the value of the knapsack.
    printf("The value of the knapsack is: %d\n", knapsack_value);

    return 0;
}