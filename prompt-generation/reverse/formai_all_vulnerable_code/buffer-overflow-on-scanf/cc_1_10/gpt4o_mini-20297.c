//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int value;
    int weight;
} Item;

// Function to compare items based on their value-to-weight ratio
int compare(const void* a, const void* b) {
    double r1 = (double)((Item*)a)->value / ((Item*)a)->weight;
    double r2 = (double)((Item*)b)->value / ((Item*)b)->weight;
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    return 0;
}

// Greedy function to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0;  // To store the total value of items in knapsack

    for (int i = 0; i < n; i++) {
        // If the item can be added fully
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // If the item can't be added fully, add the fractional part
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;  // Knapsack is full
        }
    }
    
    return totalValue;
}

int main() {
    int n; // Number of items
    int capacity; // Capacity of knapsack

    printf("Enter the number of items: ");
    scanf("%d", &n);
  
    Item* items = (Item*)malloc(n * sizeof(Item)); // Dynamically allocate memory for items

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
  
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate maximum value
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    // Free allocated memory
    free(items);
    return 0;
}