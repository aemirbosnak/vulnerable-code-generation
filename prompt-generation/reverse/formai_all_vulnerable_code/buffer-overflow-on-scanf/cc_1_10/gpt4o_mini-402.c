//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define a structure for items
typedef struct {
    int id;         // Item ID
    double weight;  // Item weight
    double value;   // Item value
    double ratio;   // Value to weight ratio
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    
    // Compare the ratios in descending order
    return (itemB->ratio > itemA->ratio) - (itemB->ratio < itemA->ratio);
}

// Function for the Greedy Knapsack Algorithm
void greedyKnapsack(Item items[], int n, double capacity) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);
    
    double totalValue = 0.0;  // Total value of items taken
    double totalWeight = 0.0;  // Total weight of items taken

    printf("Items chosen for the Knapsack (ID, Weight, Value, Ratio):\n");
    
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            // Take the whole item
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item ID: %d, Weight: %.2f, Value: %.2f, Ratio: %.2f\n", 
                   items[i].id, items[i].weight, items[i].value, items[i].ratio);
        } else {
            // Take the fraction of the remaining capacity
            double remainingCapacity = capacity - totalWeight;
            totalValue += items[i].value * (remainingCapacity / items[i].weight);
            totalWeight += remainingCapacity;
            printf("Item ID: %d, Weight: %.2f, Value: %.2f (Fraction)\n", 
                   items[i].id, remainingCapacity, items[i].value * (remainingCapacity / items[i].weight));
            break; // Knapsack is full after this
        }
    }
    
    printf("Total Value in Knapsack: %.2f\n", totalValue);
}

// Main function
int main() {
    int n;
    double capacity;

    // User input for the number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Create an array to hold items
    Item *items = (Item *)malloc(n * sizeof(Item));

    // Input the item details
    for (int i = 0; i < n; i++) {
        printf("Enter details for item %d (weight, value): ", i + 1);
        scanf("%lf %lf", &items[i].weight, &items[i].value);
        items[i].id = i + 1; // Assign ID to item
        items[i].ratio = items[i].value / items[i].weight; // Compute ratio
    }

    // User input for knapsack capacity
    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);

    // Call the greedy knapsack algorithm
    greedyKnapsack(items, n, capacity);

    // Free allocated memory
    free(items);
    
    return 0;
}