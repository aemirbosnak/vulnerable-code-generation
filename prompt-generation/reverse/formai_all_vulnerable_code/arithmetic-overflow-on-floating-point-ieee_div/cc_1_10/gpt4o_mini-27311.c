//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio; // value to weight ratio
} Item;

// Function to compare two items based on their value-to-weight ratio
int compareItems(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio > item1->ratio) - (item2->ratio < item1->ratio); // Sort in descending order
}

// Function to solve the fractional knapsack problem
void fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compareItems); // Sort items by ratio

    float totalValue = 0.0; // Total value accumulated
    int i;
    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // If the item can fit in the knapsack, take all of it
            capacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Taking entire item with weight %d and value %d\n", items[i].weight, items[i].value);
        } else {
            // Take the fraction of the item that fits
            float fraction = (float)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Taking %.2f of item with weight %d and value %d\n", fraction, items[i].weight, items[i].value);
            break; // Knapsack is full
        }
    }
    printf("Maximum value in Knapsack = %.2f\n", totalValue);
}

int main() {
    int capacity;
    int n;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input items
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        
        // Calculate the value-to-weight ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Solve the knapsack problem using a greedy approach
    fractionalKnapsack(capacity, items, n);

    // Clean up
    free(items);
    return 0;
}