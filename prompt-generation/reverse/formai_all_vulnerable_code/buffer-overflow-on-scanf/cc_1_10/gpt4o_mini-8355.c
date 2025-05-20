//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double value;
    double weight;
    double valuePerWeight;
} Item;

// Function to calculate value per weight for each item
void calculateValuePerWeight(Item *items, int count) {
    for (int i = 0; i < count; i++) {
        items[i].valuePerWeight = items[i].value / items[i].weight;
    }
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    // Sort by value per weight in descending order
    if (itemB->valuePerWeight > itemA->valuePerWeight) return 1;
    if (itemB->valuePerWeight < itemA->valuePerWeight) return -1;
    return 0;
}

// Greedy Knapsack Algorithm
double greedyKnapsack(Item *items, int itemCount, double capacity) {
    // Step 1: Calculate value per weight
    calculateValuePerWeight(items, itemCount);

    // Step 2: Sort the items by value per weight
    qsort(items, itemCount, sizeof(Item), compare);

    double totalValue = 0.0;
    for (int i = 0; i < itemCount; i++) {
        if (capacity <= 0) break; // No remaining capacity

        // Determine how much of the item to take
        if (items[i].weight <= capacity) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            totalValue += items[i].valuePerWeight * capacity;
            capacity = 0; // Full capacity is consumed
        }
    }
    return totalValue; // Return the maximum value we can carry
}

// Main function to test the greedy knapsack
int main() {
    int itemCount;
    double capacity;

    // Step 1: User input for item count and capacity
    printf("Enter the number of items: ");
    scanf("%d", &itemCount);
    
    Item *items = malloc(itemCount * sizeof(Item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the total capacity of the knapsack: ");
    scanf("%lf", &capacity);

    // Step 2: Input item details
    for (int i = 0; i < itemCount; i++) {
        printf("Enter value and weight for item %d:\n", i + 1);
        printf("Value: ");
        scanf("%lf", &items[i].value);
        printf("Weight: ");
        scanf("%lf", &items[i].weight);
        items[i].id = i + 1; // Unique ID for tracking
    }

    // Step 3: Calculate maximum value
    double maxProfit = greedyKnapsack(items, itemCount, capacity);

    // Step 4: Output the result
    printf("Maximum value in the Knapsack = %.2f\n", maxProfit);

    // Cleanup
    free(items);

    return 0;
}