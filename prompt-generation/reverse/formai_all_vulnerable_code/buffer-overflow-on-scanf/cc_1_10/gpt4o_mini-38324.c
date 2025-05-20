//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int id;           // Item ID
    int value;       // Value of the item
    int weight;      // Weight of the item
};

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r1 > r2) ? -1 : (r1 < r2) ? 1 : 0;
}

// Function to perform the fractional knapsack problem
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(items[0]), compare);
    
    double totalValue = 0.0; // Total value accumulated
    for (int i = 0; i < n; i++) {
        if (capacity > 0 && items[i].weight <= capacity) {
            capacity -= items[i].weight; // Reduce capacity by the item weight
            totalValue += items[i].value; // Add full item value
        } else {
            // Take fraction of the last item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // No capacity left
        }
    }
    return totalValue; // Return total value of knapsack
}

// Main function to demonstrate the greedy algorithm
int main() {
    int n; // Number of items
    int capacity; // Knapsack capacity

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    struct Item *items = malloc(n * sizeof(struct Item));
    if (items == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input item details
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1; // Assigning ID
        printf("Enter value and weight for item %d: ", items[i].id);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Calculate maximum value of items in knapsack
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    // Free allocated memory
    free(items);

    return 0;
}