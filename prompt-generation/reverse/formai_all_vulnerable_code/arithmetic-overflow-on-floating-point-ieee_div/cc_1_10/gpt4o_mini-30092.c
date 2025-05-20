//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    double value;
    double weight;
    double ratio;
} Item;

// Compare function for sorting items by ratio (value/weight)
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1; // Sort in descending order
    if (itemB->ratio < itemA->ratio) return -1;
    return 0;
}

// Function to perform the Fractional Knapsack algorithm
double fractionalKnapsack(int capacity, Item items[], int numItems) {
    double totalValue = 0.0;
    for (int i = 0; i < numItems; i++) {
        if (capacity == 0) {
            break; // Knapsack is full
        }
        if (items[i].weight <= capacity) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take the fraction of the remaining item
            totalValue += items[i].value * (capacity / items[i].weight);
            capacity = 0; // Knapsack is now full
        }
    }
    return totalValue;
}

int main() {
    int numItems, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item *items = (Item *)malloc(numItems * sizeof(Item));
    
    for (int i = 0; i < numItems; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].index = i + 1;
        items[i].ratio = items[i].value / items[i].weight; // Calculate ratio
    }

    // Sort items by value-to-weight ratio in decreasing order
    qsort(items, numItems, sizeof(Item), compare);

    // Calculate the maximum value that can be obtained
    double maxValue = fractionalKnapsack(capacity, items, numItems);

    printf("Maximum value in the knapsack = %.2lf\n", maxValue);

    // Free allocated memory
    free(items);
    return 0;
}