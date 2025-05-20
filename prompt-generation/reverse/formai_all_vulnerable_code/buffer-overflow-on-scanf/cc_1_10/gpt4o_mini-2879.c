//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    int weight;
    int value;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int size;
} ItemList;

// Function to sort items according to value-to-weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((Item *)a)->value / ((Item *)a)->weight;
    double r2 = (double)((Item *)b)->value / ((Item *)b)->weight;
    if (r1 < r2) return 1; // Return 1 if r1 < r2, thus sorting in descending order
    return -1; // Otherwise return -1 to maintain order
}

// Function to perform the greedy knapsack algorithm
double greedyKnapsack(ItemList *itemList, int capacity) {
    // Sort the items based on value-to-weight ratio
    qsort(itemList->items, itemList->size, sizeof(Item), compare);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < itemList->size && remainingCapacity > 0; i++) {
        if (itemList->items[i].weight <= remainingCapacity) {
            // We can take the entire item
            remainingCapacity -= itemList->items[i].weight;
            totalValue += itemList->items[i].value;
            printf("Taking full item: value = %d, weight = %d\n", itemList->items[i].value, itemList->items[i].weight);
        } else {
            // We can only take a fraction of the item
            double fraction = (double)remainingCapacity / itemList->items[i].weight;
            totalValue += itemList->items[i].value * fraction;
            printf("Taking fraction of item: value = %d, weight = %d, fraction = %.2f\n",
                   itemList->items[i].value, itemList->items[i].weight, fraction);
            remainingCapacity = 0; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    ItemList itemList;
    itemList.size = 0;

    printf("Enter the number of items: ");
    scanf("%d", &itemList.size);

    if (itemList.size > MAX_ITEMS) {
        printf("Exceeded maximum items limit of %d\n", MAX_ITEMS);
        return 1;
    }

    // Capture user-defined items
    for (int i = 0; i < itemList.size; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &itemList.items[i].value, &itemList.items[i].weight);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = greedyKnapsack(&itemList, capacity);
    printf("Maximum value obtainable in the knapsack: %.2f\n", maxValue);

    return 0;
}