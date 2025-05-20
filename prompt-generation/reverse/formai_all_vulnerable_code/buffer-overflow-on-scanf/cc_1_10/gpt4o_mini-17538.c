//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item with weight and value
typedef struct {
    int weight;
    int value;
} Item;

// Comparison function to sort items by value-to-weight ratio
int compare(const void* a, const void* b) {
    double ratio1 = (double)((Item*)b)->value / ((Item*)b)->weight;
    double ratio2 = (double)((Item*)a)->value / ((Item*)a)->weight;
    return (ratio1 > ratio2) ? 1 : -1;
}

// Greedy algorithm to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items by descending order of value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0; // Total value accumulated
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // If the item can be taken wholly
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // If the item can't be taken wholly, take the fraction
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // Knapsack is now full
        }
    }
    return totalValue; // Return maximum value achieved
}

int main() {
    int n, capacity;

    printf("Welcome to the Magical Fractional Knapsack Adventure!\n");
    printf("Enter the number of items available for your quest: ");
    scanf("%d", &n);
    
    Item* items = (Item*)malloc(n * sizeof(Item));
    
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
    }
    
    printf("Enter the capacity of your magical knapsack: ");
    scanf("%d", &capacity);
    
    double maxValue = fractionalKnapsack(capacity, items, n);
    
    printf("Your magical knapsack can carry a maximum value of: %.2f\n", maxValue);
    
    // Free allocated memory
    free(items);
    return 0;
}