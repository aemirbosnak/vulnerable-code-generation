//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double value;
    double weight;
    double ratio;
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    if (itemA->ratio < itemB->ratio) {
        return 1; // itemB has a higher ratio
    } else if (itemA->ratio > itemB->ratio) {
        return -1; // itemA has a higher ratio
    }
    return 0;
}

// Function to perform the fractional knapsack algorithm
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sorting items based on value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);
    
    double totalValue = 0.0; // Total value accumulated in the knapsack
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // If we can take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // If we can take a fraction of the item
            totalValue += items[i].value * (capacity / items[i].weight);
            break; // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n; // Number of items
    int capacity; // Capacity of the knapsack

    // Input number of items and capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input the items' value and weight
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].id = i + 1;
        items[i].ratio = items[i].value / items[i].weight; // Calculate value-to-weight ratio
    }

    // Calculate the maximum value that can be carried
    double maxValue = fractionalKnapsack(capacity, items, n);
    
    // Output the result
    printf("The maximum value that can be carried in the knapsack is: %.2lf\n", maxValue);
    
    free(items); // Free dynamically allocated memory
    return 0;
}