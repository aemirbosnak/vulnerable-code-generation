//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int value;
    int weight;
    float ratio; // value to weight ratio
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return item2->ratio - item1->ratio; // Sorting in descending order of ratio
}

float fractionalKnapsack(Item items[], int n, int capacity) {
    // Sort Items by value to weight ratio
    qsort(items, n, sizeof(Item), compare);
    
    float totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break; // No more capacity
        }

        if (items[i].weight <= capacity) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fraction of the item
            totalValue += items[i].value * ((float)capacity / items[i].weight);
            capacity = 0; // Now the knapsack is full
        }
    }
    
    return totalValue;
}

int main() {
    int n, capacity;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item *items = (Item *)malloc(n * sizeof(Item));
    
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d (separated by space): ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight; // Calculate the ratio
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    float maxValue = fractionalKnapsack(items, n, capacity);
    
    printf("Maximum value in the knapsack = %.2f\n", maxValue);
    
    // Clean up
    free(items);
    
    return 0;
}