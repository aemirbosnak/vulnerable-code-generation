//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to store the Item information
struct Item {
    int weight;
    int value;
};

// Comparison function to sort the array of items based on value-to-weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    else return 0;
}

// Function to implement the Greedy algorithm for the Knapsack problem
double knapsackGreedy(struct Item items[], int n, int capacity) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0; // Total value accumulated in the knapsack
    int currentWeight = 0; // Current weight of the knapsack
    for (int i = 0; i < n; i++) {
        // If the entire item can fit into the knapsack
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // If we cannot fit the entire item, take the fraction of it
            int remain = capacity - currentWeight;
            totalValue += items[i].value * ((double)remain / items[i].weight);
            break; // Knapsack is full
        }
    }
    return totalValue; // Total value of knapsack 
}

// Main function to demonstrate the Greedy Algorithm's knapsack solution
int main() {
    int n; // Number of items
    int capacity; // Maximum weight capacity of knapsack

    // Input the number of items and the capacity of the knapsack
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &capacity);

    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item));
    
    // Input the items' weights and values
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d (format: weight value): ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    // Calculate the maximum value of the knapsack
    double maxValue = knapsackGreedy(items, n, capacity);

    // Output the result
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    // Clean up memory
    free(items);

    return 0;
}