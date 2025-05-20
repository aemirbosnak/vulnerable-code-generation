//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int value;
    int weight;
    float ratio; // value/weight ratio
} Item;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio - item1->ratio > 0) ? 1 : -1; // Descending order
}

// Function to maximize value
float fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fractional part of the item
            totalValue += items[i].ratio * capacity;
            break; // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n; // Number of items
    int capacity; // Knapsack capacity

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item* items = (Item*)malloc(n * sizeof(Item));
    
    printf("Enter the weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight; // Calculate ratio
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    // Free allocated memory
    free(items);
    
    return 0;
}