//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
} Item;

typedef struct {
    Item *items;
    int capacity;
} Knapsack;

int compare(const void *a, const void *b) {
    // Sort items based on value to weight ratio
    double ratio1 = ((Item *)a)->value / (double)((Item *)a)->weight;
    double ratio2 = ((Item *)b)->value / (double)((Item *)b)->weight;
    if (ratio1 < ratio2) return 1; // Descending order
    if (ratio1 > ratio2) return -1;
    return 0;
}

void initializeKnapsack(Knapsack *knapsack, int capacity) {
    knapsack->capacity = capacity;
    knapsack->items = NULL; // Start with no items
}

void inputItems(Knapsack *knapsack, int numItems) {
    knapsack->items = (Item *)malloc(numItems * sizeof(Item));
    printf("Enter the value and weight of %d items:\n", numItems);
    for (int i = 0; i < numItems; i++) {
        printf("Item %d:\n", i + 1);
        printf("Value: ");
        scanf("%d", &knapsack->items[i].value);
        printf("Weight: ");
        scanf("%d", &knapsack->items[i].weight);
    }
}

void freeKnapsack(Knapsack *knapsack) {
    free(knapsack->items);
    knapsack->items = NULL;
}

double knapsackGreedy(Knapsack knapsack) {
    // Sort items based on their value to weight ratio
    qsort(knapsack.items, knapsack.capacity, sizeof(Item), compare);

    double totalValue = 0.0;
    int remainingCapacity = knapsack.capacity;

    for (int i = 0; i < knapsack.capacity; i++) {
        if (knapsack.items[i].weight <= remainingCapacity) {
            // If item can be accommodated whole
            printf("Taking whole item %d [Value: %d, Weight: %d]\n", i + 1, knapsack.items[i].value, knapsack.items[i].weight);
            totalValue += knapsack.items[i].value;
            remainingCapacity -= knapsack.items[i].weight;
        } else {
            // Taking fraction of the item
            double fraction = (double)remainingCapacity / knapsack.items[i].weight;
            printf("Taking %.2f fraction of item %d [Value: %d, Weight: %d]\n", fraction, i + 1, knapsack.items[i].value, knapsack.items[i].weight);
            totalValue += knapsack.items[i].value * fraction;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

void displayResult(double totalValue) {
    printf("Total value in knapsack: %.2f\n", totalValue);
}

int main() {
    Knapsack knapsack;
    int numItems, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    printf("Enter the total weight capacity of the knapsack: ");
    scanf("%d", &capacity);

    initializeKnapsack(&knapsack, numItems);
    inputItems(&knapsack, numItems);

    double totalValue = knapsackGreedy(knapsack);
    displayResult(totalValue);

    freeKnapsack(&knapsack);
    return 0;
}