//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

// Function to compare two items according to their value to weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r1 < r2) ? -1 : (r1 > r2);
}

// Function to get the maximum value of items that can be accommodated in the knapsack
double knapsack(int capacity, struct Item items[], int n) {
    // Sort the items by value/weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0; // Total value in knapsack

    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break; // Return if capacity becomes 0
        }

        // Find the maximum weight that can be put in the knapsack
        if (items[i].weight <= capacity) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fractional part of the last item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // Knapsack is now full
        }
    }

    return totalValue; // Return the maximum value
}

int main() {
    int n; // Number of items
    int capacity; // Knapsack capacity

    // Input number of items and capacity
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item));

    // Input items
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate maximum value
    double maxValue = knapsack(capacity, items, n);
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    // Free dynamically allocated memory
    free(items);
    
    return 0;
}