//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare two items based on their value to weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r1 < r2) ? -1 : (r1 > r2) ? 1 : 0;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(items[0]), compare);
    
    double totalValue = 0.0;

    // Iterate through the sorted items
    for (int i = n - 1; i >= 0; i--) {
        if (items[i].weight <= capacity) {
            // If the item can fit in the knapsack, take it whole
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // If the item cannot fit, take the fraction of it
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // Since the knapsack is full
        }
    }
    
    return totalValue;
}

int main() {
    int n;

    // Prompt the user for the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input details for each item
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Calculate the maximum value
    double maxValue = fractionalKnapsack(capacity, items, n);
    
    // Output the result
    printf("Maximum value in the knapsack = %.2f\n", maxValue);
    
    return 0;
}