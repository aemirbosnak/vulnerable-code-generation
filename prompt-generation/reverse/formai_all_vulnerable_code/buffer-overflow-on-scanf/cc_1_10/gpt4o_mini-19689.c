//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int value;
    int weight;
} Item;

typedef struct Knapsack {
    int capacity;
    int numItems;
    Item *items;
} Knapsack;

int compareItems(const void *a, const void *b) {
    double ratio1 = (double)((Item *)a)->value / ((Item *)a)->weight;
    double ratio2 = (double)((Item *)b)->value / ((Item *)b)->weight;
    
    if (ratio1 < ratio2) return 1;
    if (ratio1 > ratio2) return -1;
    return 0;
}

double greedyKnapsack(Knapsack *knapsack) {
    // Sorting the items based on value-to-weight ratio
    qsort(knapsack->items, knapsack->numItems, sizeof(Item), compareItems);

    double totalValue = 0.0;
    int currentCapacity = knapsack->capacity;

    for (int i = 0; i < knapsack->numItems; i++) {
        if (currentCapacity == 0) break;

        // Take the whole item if it fits
        if (knapsack->items[i].weight <= currentCapacity) {
            totalValue += knapsack->items[i].value;
            currentCapacity -= knapsack->items[i].weight;
        } else { // Take the fraction of the item
            totalValue += knapsack->items[i].value * ((double)currentCapacity / knapsack->items[i].weight);
            currentCapacity = 0; // Knapsack is full
        }
    }
    return totalValue;
}

void printKnapsack(Knapsack *knapsack) {
    printf("Knapsack Capacity: %d\n", knapsack->capacity);
    printf("Items:\n");
    for (int i = 0; i < knapsack->numItems; i++) {
        printf("Item %d: Value = %d, Weight = %d\n", i + 1, knapsack->items[i].value, knapsack->items[i].weight);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Knapsack knapsack;
    knapsack.numItems = n;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &knapsack.capacity);

    knapsack.items = (Item *)malloc(n * sizeof(Item));
    if (knapsack.items == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Reading items
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &(knapsack.items[i].value), &(knapsack.items[i].weight));
    }

    printKnapsack(&knapsack);
    
    double maxValue = greedyKnapsack(&knapsack);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    free(knapsack.items); // Freeing allocated memory
    return 0;
}