//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double value;
    double weight;
    double value_per_weight;
} Item;

// Function to compare two items based on their value-to-weight ratio
int compareItems(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;

    if (item1->value_per_weight < item2->value_per_weight) {
        return 1; // Return 1 if item1 has a lower value/weight ratio
    } else if (item1->value_per_weight > item2->value_per_weight) {
        return -1; // Return -1 if item1 has a higher value/weight ratio
    } else {
        return 0; // Treat as equal
    }
}

// Function to perform the fractional knapsack algorithm
double fractionalKnapsack(Item items[], int n, double capacity) {
    double totalValue = 0.0; // To store the maximum value that can be carried

    // Sort items based on value/weight ratio
    qsort(items, n, sizeof(Item), compareItems);

    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break; // If the knapsack is full
        }
        if (items[i].weight <= capacity) {
            // We can take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // We can take a fraction of the item
            totalValue += items[i].value_per_weight * capacity;
            capacity = 0; // Knapsack is now full
        }
    }
    return totalValue;
}

int main() {
    int n;
    double capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item* items = (Item*)malloc(n * sizeof(Item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].id = i + 1;
        items[i].value_per_weight = items[i].value / items[i].weight; // Calculate value/weight ratio
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);

    double maxValue = fractionalKnapsack(items, n, capacity);

    printf("Maximum value in the knapsack = %.2lf\n", maxValue);

    // Free allocated memory
    free(items);

    return 0;
}