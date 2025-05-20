//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double value;
    double weight;
    double valuePerWeight;
} Item;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    if (itemA->valuePerWeight < itemB->valuePerWeight) {
        return 1; // For descending order
    }
    return -1;
}

double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity <= 0) {
            break; // Knapsack is full
        }

        // If the item can be accommodated completely
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else { // If the item cannot be accommodated completely
            totalValue += items[i].valuePerWeight * capacity;
            capacity = 0; // Knapsack is full now
        }
    }

    return totalValue;
}

void printItems(Item items[], int n) {
    printf("Items (ID, Value, Weight, Value/Weight):\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Value: %.2f, Weight: %.2f, Value/Weight: %.2f\n", 
               items[i].id, items[i].value, items[i].weight, items[i].valuePerWeight);
    }
}

int main() {
    int n, capacity;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));
    
    // Input item details
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].id = i + 1;
        items[i].valuePerWeight = items[i].value / items[i].weight; // Calculate value-to-weight ratio
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Displaying input items
    printItems(items, n);

    double maxProfit = fractionalKnapsack(capacity, items, n);
    printf("Maximum profit in the knapsack: %.2f\n", maxProfit);

    free(items);
    return 0;
}