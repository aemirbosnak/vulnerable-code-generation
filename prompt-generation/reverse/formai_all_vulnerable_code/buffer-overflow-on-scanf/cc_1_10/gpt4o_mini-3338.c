//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int value;
    int weight;
    float ratio; // value-to-weight ratio
} Item;

// Function to compare Items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    
    if (itemA->ratio < itemB->ratio) {
        return 1; // itemB is more desirable
    } else if (itemA->ratio > itemB->ratio) {
        return -1; // itemA is more desirable
    }
    return 0; // equal desirability
}

// Function to perform the Fractional Knapsack Problem
float fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items based on value-to-weight ratio
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    qsort(items, n, sizeof(Item), compare);
    
    float totalValue = 0; // Total value accumulated
    for (int i = 0; i < n; i++) {
        if (capacity > 0 && items[i].weight <= capacity) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else if (capacity > 0) {
            // Take the fraction of the remaining item
            totalValue += items[i].ratio * capacity;
            capacity = 0; // Knapsack is full
            break;
        }
    }
    
    return totalValue; // Return the maximum value
}

// Driver function
int main() {
    int n; // Number of items
    int capacity; // Capacity of knapsack

    // User inputs for number of items and capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item *items = malloc(n * sizeof(Item)); // Allocate memory for items
    
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    
    // User inputs for value and weight of each item
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    
    // Calculate maximum value that can be carried
    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack = %.2f\n", maxValue);
    
    // Free allocated memory
    free(items);
    
    return 0; // Exit the program successfully
}