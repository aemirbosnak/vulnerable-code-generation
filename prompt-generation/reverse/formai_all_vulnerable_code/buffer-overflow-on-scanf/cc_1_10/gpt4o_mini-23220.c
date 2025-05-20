//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Comparison function to sort items based on value/weight ratio
int compare(const void *a, const void *b) {
    double ratio1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double ratio2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (ratio1 < ratio2) ? 1 : -1; // Sort in descending order
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    // Sort items by value to weight ratio
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0; // Total value of items taken
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // If the item can be fully taken
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // If the item cannot be fully taken
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *items = (struct Item*)malloc(n * sizeof(struct Item));
    
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    free(items); // Free the allocated memory
    return 0;
}