//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int weight;
    int value;
} Item;

typedef struct {
    int capacity;
    int itemCount;
    Item *items;
} Knapsack;

void printItems(Item *items, int count) {
    printf("Items:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Weight: %d, Value: %d\n", items[i].id, items[i].weight, items[i].value);
    }
}

int compare(const void *a, const void *b) {
    double r1 = ((Item *)a)->value / (double)((Item *)a)->weight;
    double r2 = ((Item *)b)->value / (double)((Item *)b)->weight;
    return (r1 < r2) ? 1 : (r1 > r2) ? -1 : 0;
}

void knapsackGreedy(Knapsack knapsack) {
    qsort(knapsack.items, knapsack.itemCount, sizeof(Item), compare);

    int totalValue = 0;
    int totalWeight = 0;

    printf("\nSelected Items for Knapsack of Capacity %d:\n", knapsack.capacity);
    
    for (int i = 0; i < knapsack.itemCount; i++) {
        if (totalWeight + knapsack.items[i].weight <= knapsack.capacity) {
            totalWeight += knapsack.items[i].weight;
            totalValue += knapsack.items[i].value;
            printf("Included Item ID: %d, Weight: %d, Value: %d\n", knapsack.items[i].id, knapsack.items[i].weight, knapsack.items[i].value);
        } else {
            printf("Cannot include Item ID: %d, Weight: %d, Value: %d (Exceeds capacity)\n", knapsack.items[i].id, knapsack.items[i].weight, knapsack.items[i].value);
        }
    }
    printf("\nTotal Weight: %d\nTotal Value: %d\n", totalWeight, totalValue);
}

int main() {
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int itemCount;
    printf("Enter the number of items: ");
    scanf("%d", &itemCount);

    Item *items = (Item *)malloc(itemCount * sizeof(Item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < itemCount; i++) {
        items[i].id = i + 1;
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    Knapsack knapsack;
    knapsack.capacity = capacity;
    knapsack.itemCount = itemCount;
    knapsack.items = items;

    printItems(items, itemCount);
    
    knapsackGreedy(knapsack);

    free(items);
    return EXIT_SUCCESS;
}