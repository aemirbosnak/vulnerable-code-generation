//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int value;   // The value of the item
    int weight;  // The weight of the item
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    double r1 = ((Item *)a)->value / (double)((Item *)a)->weight;
    double r2 = ((Item *)b)->value / (double)((Item *)b)->weight;
    return (r1 < r2) ? -1 : (r1 > r2) ? 1 : 0;
}

// Greedy algorithm to solve the Fractional Knapsack problem
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);
    
    double totalValue = 0.0; // To store the total value of items

    // Loop through all the items
    for (int i = 0; i < n; i++) {
        // If adding the entire item would go over capacity, add the fractional part
        if (capacity == 0) {
            break;
        }
        if (items[i].weight <= capacity) {
            totalValue += items[i].value; // Take full item
            capacity -= items[i].weight; // Decrease capacity
        } else { // Take the fractional part
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0; // Full capacity utilized
        }
    }

    return totalValue; // Return the total value of items fitted in the knapsack
}

int main() {
    int n, capacity;

    // Read number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    // Read capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    Item *items = (Item *)malloc(n * sizeof(Item)); // Allocate memory for items

    // Read the value and weight for each item
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Calculate the maximum value that can be stored in the knapsack
    double maxValue = fractionalKnapsack(capacity, items, n);

    // Display the result
    printf("The maximum value that can be obtained is: %.2lf\n", maxValue);

    // Free allocated memory
    free(items);
    
    return 0; // Successful completion of the program
}