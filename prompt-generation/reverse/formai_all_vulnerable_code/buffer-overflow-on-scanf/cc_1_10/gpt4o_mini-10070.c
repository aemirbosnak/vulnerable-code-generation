//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int comparator(const void *a, const void *b) {
    double r1 = (double)((Item *)a)->value / ((Item *)a)->weight;
    double r2 = (double)((Item *)b)->value / ((Item *)b)->weight;
    return (r1 < r2) ? -1 : (r1 > r2);
}

void greedyKnapsack(Item items[], int numItems, int maxWeight) {
    // Sort items based on value-to-weight ratio
    qsort(items, numItems, sizeof(Item), comparator);
    
    int totalWeight = 0;
    double totalValue = 0.0;

    printf("Selected Items:\n");
    for (int i = numItems - 1; i >= 0; i--) {
        if (totalWeight + items[i].weight <= maxWeight) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d - Weight: %d, Value: %d\n", i + 1, items[i].weight, items[i].value);
        }
    }

    printf("Total Weight: %d\n", totalWeight);
    printf("Total Value: %.2f\n", totalValue);
}

int main() {
    int numItems, maxWeight;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    Item *items = (Item *)malloc(numItems * sizeof(Item));

    printf("Enter the max weight of the knapsack: ");
    scanf("%d", &maxWeight);

    printf("Enter weight and value of each item (one per line, space-separated):\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    greedyKnapsack(items, numItems, maxWeight);

    free(items);
    return 0;
}