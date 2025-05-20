//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int weight;
    int value;
    float ratio; // Value to Weight ratio
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio > item2->ratio) return -1;
    if (item1->ratio < item2->ratio) return 1;
    return 0;
}

void greedyKnapsack(Item items[], int numItems, int capacity) {
    qsort(items, numItems, sizeof(Item), compare);
    
    int totalValue = 0;
    int totalWeight = 0;

    printf("Selected items:\n");
    for (int i = 0; i < numItems; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Value = %d, Weight = %d, Ratio = %.2f\n", 
                    i, items[i].value, items[i].weight, items[i].ratio);
        } else {
            float remainingCapacity = capacity - totalWeight;
            if (remainingCapacity > 0) {
                totalValue += items[i].value * (remainingCapacity / items[i].weight);
                printf("Item %d: Value = %.2f (Fractional), Weight = %.2f (Fractional), Ratio = %.2f\n", 
                        i, items[i].value * (remainingCapacity / items[i].weight), remainingCapacity, items[i].ratio);
            }
            break;
        }
    }
    
    printf("Total value in knapsack = %d\n", totalValue);
}

int main() {
    int numItems, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    
    Item *items = (Item *)malloc(numItems * sizeof(Item));

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < numItems; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight; // Calculate value-to-weight ratio
    }

    greedyKnapsack(items, numItems, capacity);

    free(items);
    return 0;
}