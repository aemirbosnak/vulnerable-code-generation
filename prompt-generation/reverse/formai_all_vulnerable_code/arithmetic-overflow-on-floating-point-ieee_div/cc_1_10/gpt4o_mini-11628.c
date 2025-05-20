//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    double value;
    double weight;
    double ratio;
} Item;

// Comparison function for sorting items based on value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return (itemB->ratio > itemA->ratio) - (itemB->ratio < itemA->ratio);
}

// Function to solve the fractional knapsack problem
double fractional_knapsack(int capacity, Item items[], int n) {
    // Sort items based on value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity <= 0) {
            break; // Knapsack is full
        }

        if (items[i].weight <= capacity) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fraction of the remaining item
            totalValue += items[i].value * (capacity / items[i].weight);
            capacity = 0; // Knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int n;
    int capacity;
    
    // Input the number of items and the capacity of the knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item *items = malloc(n * sizeof(Item)); // Dynamically allocate memory for items

    // Input the values and weights of each item
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].index = i; // Store item index
        items[i].ratio = items[i].value / items[i].weight; // Calculate value-to-weight ratio
    }

    double maxValue = fractional_knapsack(capacity, items, n);

    // Output the result
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    free(items); // Free dynamically allocated memory
    return 0;
}