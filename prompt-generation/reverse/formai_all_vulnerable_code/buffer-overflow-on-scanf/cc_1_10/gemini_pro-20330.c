//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int value;
    int weight;
} Item;

Item items[MAX_ITEMS];
int n_items;

int compare_items(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;

    double value_per_weight1 = (double)item1->value / item1->weight;
    double value_per_weight2 = (double)item2->value / item2->weight;

    if (value_per_weight1 < value_per_weight2) {
        return -1;
    } else if (value_per_weight1 > value_per_weight2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Get the number of items.
    printf("Enter the number of items: ");
    scanf("%d", &n_items);

    // Get the items.
    for (int i = 0; i < n_items; i++) {
        printf("Enter the name, value, and weight of item %d: ", i + 1);
        scanf("%s %d %d", items[i].name, &items[i].value, &items[i].weight);
    }

    // Sort the items in decreasing order of value per weight.
    qsort(items, n_items, sizeof(Item), compare_items);

    // Initialize the knapsack.
    int knapsack_capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &knapsack_capacity);

    int knapsack[MAX_ITEMS];
    memset(knapsack, 0, sizeof(knapsack));

    // Fill the knapsack greedily.
    int total_value = 0;
    int total_weight = 0;
    for (int i = 0; i < n_items; i++) {
        if (total_weight + items[i].weight <= knapsack_capacity) {
            knapsack[i] = 1;
            total_value += items[i].value;
            total_weight += items[i].weight;
        }
    }

    // Print the contents of the knapsack.
    printf("The contents of the knapsack are:\n");
    for (int i = 0; i < n_items; i++) {
        if (knapsack[i]) {
            printf("%s (%d, %d)\n", items[i].name, items[i].value, items[i].weight);
        }
    }

    // Print the total value and weight of the knapsack.
    printf("Total value: %d\n", total_value);
    printf("Total weight: %d\n", total_weight);

    return 0;
}