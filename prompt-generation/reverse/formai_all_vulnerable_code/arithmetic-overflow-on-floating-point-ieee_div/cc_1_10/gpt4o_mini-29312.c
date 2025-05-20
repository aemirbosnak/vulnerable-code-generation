//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    double value;
    double valuePerWeight;
} Item;

// Comparison function for sorting items by value per weight
int compare(const void *a, const void *b) {
    double ratio1 = ((Item *)a)->valuePerWeight;
    double ratio2 = ((Item *)b)->valuePerWeight;
    if (ratio1 < ratio2) return 1;
    else if (ratio1 > ratio2) return -1;
    return 0;
}

// Function to perform the Greedy Knapsack algorithm
double greedyKnapsack(Item items[], int n, int capacity) {
    // Sort items based on value per weight
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity == 0) break;
        
        // If the whole item can be taken
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } 
        // If a fraction of the item can be taken
        else {
            totalValue += items[i].valuePerWeight * capacity;
            capacity = 0; // Knapsack is full
        }
    }
    return totalValue;
}

// Utility function to create an item
Item createItem(int weight, double value) {
    Item item;
    item.weight = weight;
    item.value = value;
    item.valuePerWeight = value / weight; // Calculate value per weight ratio
    return item;
}

// Main function to test the Greedy Knapsack implementation
int main() {
    int n; // Number of items
    int capacity; // Capacity of the knapsack

    // Input section
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Create array of items
    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Input item details
    for (int i = 0; i < n; i++) {
        int weight;
        double value;
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %lf", &weight, &value);
        items[i] = createItem(weight, value);
    }

    // Calculate maximum value obtainable with the given knapsack capacity
    double maxValue = greedyKnapsack(items, n, capacity);
    printf("Maximum value obtainable: %.2lf\n", maxValue);

    // Free the allocated memory
    free(items);
    return 0;
}