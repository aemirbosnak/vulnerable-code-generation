//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    double ratioA = (double)((Item *)a)->value / ((Item *)a)->weight;
    double ratioB = (double)((Item *)b)->value / ((Item *)b)->weight;
    return (ratioA < ratioB) - (ratioA > ratioB); // For qsort comparison
}

void knapsackGreedy(Item *items, int numItems, int capacity) {
    qsort(items, numItems, sizeof(Item), compare); // Sort items by value/weight ratio

    int totalValue = 0;
    int currentWeight = 0;

    printf("Items added to the knapsack:\n");

    for (int i = numItems - 1; i >= 0; i--) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Added item with weight: %d and value: %d\n", items[i].weight, items[i].value);
        }
    }

    printf("Total weight in knapsack: %d\n", currentWeight);
    printf("Total value in knapsack: %d\n", totalValue);
}

int main() {
    int numItems;
    int capacity;

    printf("Enter the total number of items: ");
    scanf("%d", &numItems);

    if (numItems <= 0) {
        printf("Number of items must be positive.\n");
        return 1;
    }

    Item *items = (Item *)malloc(numItems * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < numItems; i++) {
        printf("Enter weight and value of item %d (space-separated): ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        if (items[i].weight < 0 || items[i].value < 0) {
            printf("Weight and value must be non-negative.\n");
            free(items);
            return 1;
        }
    }

    knapsackGreedy(items, numItems, capacity);

    free(items);
    return 0;
}