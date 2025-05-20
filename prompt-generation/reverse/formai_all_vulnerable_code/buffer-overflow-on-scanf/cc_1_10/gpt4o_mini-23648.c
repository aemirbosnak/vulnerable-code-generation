//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
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

// Greedy function to calculate the maximum value of items that can be carried
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(Item), compare);
    
    double totalValue = 0.0;  // Total value of knapsack
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // If the item's weight is less than or equal to the remaining capacity
            capacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Taking whole item with value: %d, weight: %d\n", items[i].value, items[i].weight);
        } else {
            // If the item's weight is more than the remaining capacity
            double fraction = (double)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Taking fractional item with value: %d, weight: %d (taking %f)\n",
                   items[i].value, items[i].weight, fraction);
            break;  // Knapsack is full
        }
    }
    
    return totalValue;
}

// Main function
int main() {
    int n;  // Number of items
    int capacity;  // Maximum capacity of the knapsack

    // Input number of items and capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item *items = (Item *)malloc(n * sizeof(Item));  // Dynamic array of items
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return -1;  // Exit program if memory allocation fails
    }

    // Input values and weights of items
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate the maximum value of the knapsack
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    // Clean up
    free(items);

    return 0;  // Successful execution
}