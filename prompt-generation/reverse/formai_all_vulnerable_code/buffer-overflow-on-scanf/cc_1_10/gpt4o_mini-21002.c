//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;   // The value of the item
    int weight;  // The weight of the item
} Item;

// Function to compare two items based on their value to weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((Item *)a)->value / (double)((Item *)a)->weight;
    double r2 = (double)((Item *)b)->value / (double)((Item *)b)->weight;
    return (r1 < r2) ? 1 : -1; // Sort in descending order
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort the items by their value to weight ratio
    qsort(items, n, sizeof(items[0]), compare);
    
    double totalValue = 0.0; // Variable to store the total value accumulated
    
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break; // If capacity is full, break the loop
        }
        // If the item's weight is less than or equal to remaining capacity
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight; // Reduce the remaining capacity
            totalValue += items[i].value; // Add the value of the item to total
        } else {
            // Item cannot fit completely, take the fraction of it
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0; // Knapsack is full
        }
    }
    
    return totalValue; // Return the maximum total value
}

int main() {
    int n; // Number of items
    int capacity; // Max capacity of the knapsack
    
    // User input for number of items and the capacity of the knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item *items = (Item *)malloc(n * sizeof(Item)); // Dynamic allocation for items
    
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    // Input values and weights for each item
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    
    // Input knapsack capacity
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    // Calculate the maximum obtainable value using the greedy approach
    double maxValue = fractionalKnapsack(capacity, items, n);
    
    printf("The maximum value that can be obtained is: %.2f\n", maxValue);
    
    free(items); // Free dynamically allocated memory
    return 0; // Successful termination
}