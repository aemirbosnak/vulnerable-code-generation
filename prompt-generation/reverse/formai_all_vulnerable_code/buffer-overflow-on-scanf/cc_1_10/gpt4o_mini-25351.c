//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

// Structure to represent an item with weight and value
typedef struct {
    int value;
    int weight;
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratio1 = (double)((Item *)a)->value / ((Item *)a)->weight;
    double ratio2 = (double)((Item *)b)->value / ((Item *)b)->weight;
    return (ratio1 < ratio2) - (ratio1 > ratio2);
}

// Greedy Knapsack function
double greedyKnapsack(Item items[], int numItems, int capacity) {
    // Sort items by value-to-weight ratio
    qsort(items, numItems, sizeof(Item), compare);
    
    double totalValue = 0.0; // Total value accumulated
    for (int i = 0; i < numItems; i++) {
        if (capacity <= 0) {
            break; // If the capacity is full, break out of the loop
        }
        // If the item can be fully added to the knapsack
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // If the item cannot be fully added, add a fraction of it
            double fractional = (double)capacity / items[i].weight;
            totalValue += items[i].value * fractional;
            capacity = 0; // Fill the knapsack, capacity is now 0
        }
    }
    
    return totalValue;
}

// Main function to drive the Greedy Knapsack implementation
int main() {
    // Declaration of items and other variables
    Item items[MAX_ITEMS];
    int numItems, capacity;
    
    // Enter the number of items
    printf("Enter the number of items: ");
    if (scanf("%d", &numItems) != 1 || numItems <= 0 || numItems > MAX_ITEMS) {
        fprintf(stderr, "Invalid number of items. Please provide a positive integer up to %d.\n", MAX_ITEMS);
        return EXIT_FAILURE; // Exit on invalid input
    }

    // Input each item's value and weight
    for (int i = 0; i < numItems; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        if (scanf("%d %d", &items[i].value, &items[i].weight) != 2 || items[i].weight <= 0) {
            fprintf(stderr, "Invalid input for item %d. Ensure you enter two positive integers.\n", i + 1);
            return EXIT_FAILURE; // Exit on invalid input
        }
    }

    // Enter the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        fprintf(stderr, "Invalid capacity. Please provide a positive integer.\n");
        return EXIT_FAILURE; // Exit on invalid input
    }

    // Calculate maximum value that can be accommodated in the knapsack
    double maxValue = greedyKnapsack(items, numItems, capacity);
    
    // Output the result
    printf("Maximum value that can be accommodated in the knapsack: %.2f\n", maxValue);
    
    return EXIT_SUCCESS; // Successful completion
}