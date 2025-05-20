//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

// Function to compare two items according to their value per weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r1 < r2) ? -1 : (r1 > r2) ? 1 : 0;
}

// Function to implement the Greedy algorithm for the Knapsack Problem
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0; // Total value of items added to the knapsack

    for (int i = 0; i < n; i++) {
        if (capacity <= 0) {
            break; // Knapsack is full
        }

        // If item can be fully added, add its full value to the total
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else { // Otherwise, add the fractional part of the item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0; // Knapsack is now full
        }
    }
    return totalValue;
}

int main() {
    int n; // Number of items
    int capacity; // Maximum capacity of the knapsack

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item));
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with an error if memory allocation fails
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter value and weight of each item (value weight):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate the maximum value that can be obtained
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    free(items); // Free the allocated memory
    return 0;
}