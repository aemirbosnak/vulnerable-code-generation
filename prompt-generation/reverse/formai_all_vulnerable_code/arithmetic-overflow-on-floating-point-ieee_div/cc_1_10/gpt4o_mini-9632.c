//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio; // value-to-weight ratio
} Item;

// Function to compare items based on their ratio for sorting
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio < item2->ratio) return 1;
    else if (item1->ratio > item2->ratio) return -1;
    else return 0;
}

// Greedy function to maximize value
float knapsack(Item *items, int numItems, int capacity) {
    float totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < numItems; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Taking item with weight %d and value %d\n", 
                   items[i].weight, items[i].value);
        } else {
            // Take the fraction of the item
            int remain = capacity - currentWeight;
            totalValue += items[i].value * ((float) remain / items[i].weight);
            printf("Taking fraction of item with weight %d and value %d\n", 
                   items[i].weight, items[i].value);
            break; // The knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int numItems;
    int capacity;

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    Item *items = (Item *)malloc(numItems * sizeof(Item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Input item weights and values
    for (int i = 0; i < numItems; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d%d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Sort items by value-to-weight ratio in decreasing order
    qsort(items, numItems, sizeof(Item), compare);

    // Calculate the maximum value in the knapsack
    float maxValue = knapsack(items, numItems, capacity);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    // Free allocated memory
    free(items);
    return 0;
}