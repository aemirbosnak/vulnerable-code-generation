//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;  // Value of the item
    int weight; // Weight of the item
} Item;

// Comparison function for sorting items based on their value-to-weight ratio
int compare(const void* a, const void* b) {
    double r1 = (double)((Item*)a)->value / ((Item*)a)->weight;
    double r2 = (double)((Item*)b)->value / ((Item*)b)->weight;
    return (r1 < r2) - (r1 > r2);  // Returns -1, 0, or 1
}

// Function to get the maximum value of items that can fit in the knapsack
double fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);  // Sort items by value-to-weight ratio

    double totalValue = 0.0;  // Total maximum value we can get
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break;  // If the capacity is full, exit the loop
        }
        if (items[i].weight <= capacity) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take the fraction of the remaining item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0;  // Knapsack is full
        }
    }
    return totalValue;  // Return total value
}

int main() {
    int n;  // Number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item* items = malloc(n * sizeof(Item));  // Dynamically allocate memory for items

    // Input item values and weights
    printf("Enter value and weight of each item (value weight):\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;  // Capacity of knapsack
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(capacity, items, n);  // Calculate max value
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    free(items);  // Free allocated memory
    return 0;
}