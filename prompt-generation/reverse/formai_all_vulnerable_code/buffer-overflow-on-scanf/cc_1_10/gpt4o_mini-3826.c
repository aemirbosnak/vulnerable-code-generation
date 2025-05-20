//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare two items based on their value-to-weight ratio
int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r1 < r2) ? -1 : (r1 > r2) ? 1 : 0;
}

// Function to perform the fractional knapsack problem using a greedy approach
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items by value/weight ratio
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0;  // Total value of items in the knapsack
    int i;

    // Iterate through items
    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // If the item can be fully added
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // If the item can only be partially added
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n; // Number of items
    int capacity; // Capacity of knapsack

    // Input number of items and capacity of knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    struct Item* items = (struct Item*)malloc(n * sizeof(struct Item));

    // Input value and weight of each item
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate maximum value in knapsack
    double maxValue = fractionalKnapsack(capacity, items, n);

    // Output the result
    printf("Maximum value in the knapsack = %lf\n", maxValue);

    // Clean up
    free(items);

    return 0;
}