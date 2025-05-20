//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    int weight;
    int value;
} Item;

// Function to compare two items, used for sorting
int compare(const void *a, const void *b) {
    double ratio1 = (double)((Item *)a)->value / ((Item *)a)->weight;
    double ratio2 = (double)((Item *)b)->value / ((Item *)b)->weight;
    return (ratio1 < ratio2) - (ratio1 > ratio2);
}

// Greedy algorithm to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(Item), compare);
    
    double totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break;  // No capacity left
        }
        
        // If the item's weight is less than or equal to remaining capacity
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take the fraction of the remaining item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0;  // Knapsack is full
        }
    }
    
    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[MAX_ITEMS];
    
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    
    double maxValue = fractionalKnapsack(capacity, items, n);
    
    printf("Maximum value in the Knapsack = %.2f\n", maxValue);

    return 0;
}