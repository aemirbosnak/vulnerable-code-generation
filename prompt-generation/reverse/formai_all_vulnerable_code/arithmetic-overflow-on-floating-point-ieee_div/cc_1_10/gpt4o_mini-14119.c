//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio; // value per weight
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    
    // Compare based on the value to weight ratio
    if (itemA->ratio < itemB->ratio) return 1;
    else if (itemA->ratio > itemB->ratio) return -1;
    else return 0;
}

void knapsackGreedy(Item items[], int numItems, int capacity) {
    qsort(items, numItems, sizeof(Item), compare);

    float totalValue = 0.0;
    int remainingCapacity = capacity;

    printf("Items selected:\n");
    for (int i = 0; i < numItems; i++) {
        if (remainingCapacity <= 0) break;

        if (items[i].weight <= remainingCapacity) {
            // Take the whole item
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Item %d (Value: %d, Weight: %d)\n", i, items[i].value, items[i].weight);
        } else {
            // Take a fraction of the item
            float fraction = (float)remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Item %d (Value: %d, Weight: %d, Taken Fraction: %.2f)\n", i, items[i].value, items[i].weight, fraction);
            remainingCapacity = 0; // Knapsack is full
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
}

int main() {
    int numItems, capacity;

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    Item *items = (Item *)malloc(numItems * sizeof(Item));

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d weight: ", i);
        scanf("%d", &items[i].weight);
        printf("Item %d value: ", i);
        scanf("%d", &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight; // Compute ratio
    }

    knapsackGreedy(items, numItems, capacity);

    // Free allocated memory
    free(items);

    return 0;
}