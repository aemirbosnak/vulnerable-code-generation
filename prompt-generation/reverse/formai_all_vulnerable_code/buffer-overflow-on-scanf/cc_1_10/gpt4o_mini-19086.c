//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double ratio; // value/weight ratio
} Item;

// Comparison function for qsort
int compare(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    return (itemB->ratio < itemA->ratio) - (itemB->ratio > itemA->ratio);
}

// Function to calculate maximum value that can be put in knapsack
double fractionalKnapsack(int capacity, Item* items, int n) {
    // Sort items by their value to weight ratio
    qsort(items, n, sizeof(Item), compare);
    
    double maxValue = 0.0; // Maximum value in knapsack
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break; // if knapsack is full, break the loop
        }
        
        if (items[i].weight <= capacity) {
            // If we can take the whole item
            capacity -= items[i].weight;
            maxValue += items[i].value;
            printf("Taking full item: value = %d, weight = %d\n", items[i].value, items[i].weight);
        } else {
            // Take the fraction of the item that fits
            double fraction = (double)capacity / items[i].weight;
            maxValue += items[i].value * fraction;
            printf("Taking fraction of item: value = %d, weight = %d, fraction = %.2f\n", items[i].value, items[i].weight, fraction);
            capacity = 0; // knapsack is full
        }
    }
    
    return maxValue;
}

int main() {
    int n, capacity;
    printf("Welcome to the Fractional Knapsack Problem solver!\n");
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item* items = malloc(n * sizeof(Item));
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight; // calculate value/weight ratio
    }
    
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in knapsack: %.2f\n", maxValue);
    
    free(items); // free allocated memory
    return 0;
}