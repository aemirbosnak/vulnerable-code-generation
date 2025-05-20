//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void printItems(Item items[], int count) {
    printf("Available items:\n");
    for (int i = 0; i < count; i++) {
        printf("Item %d - Weight: %d, Value: %d\n", items[i].id, items[i].weight, items[i].value);
    }
}

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
}

void greedyKnapsack(Item items[], int count, int capacity) {
    qsort(items, count, sizeof(Item), compare);

    int currentWeight = 0;
    int currentValue = 0;

    printf("Choosing items for the journey...\n");

    for (int i = 0; i < count; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            currentValue += items[i].value;
            printf("Added Item %d: Weight: %d, Value: %d\n", items[i].id, items[i].weight, items[i].value);
        } else {
            printf("Skipped Item %d: Weight: %d, Value: %d (not enough capacity)\n", items[i].id, items[i].weight, items[i].value);
        }
    }

    printf("\nTotal weight carried: %d\n", currentWeight);
    printf("Total value gathered: %d\n", currentValue);
}

int main() {
    Item items[MAX_ITEMS];
    int itemCount = 0;
    int capacity;

    printf("Enter the carrying capacity of your scavenging pack: ");
    scanf("%d", &capacity);

    printf("\nIn this post-apocalyptic wasteland, you will need to gather supplies to survive.\n");
    printf("Enter the number of items you found: ");
    scanf("%d", &itemCount);

    for (int i = 0; i < itemCount; i++) {
        items[i].id = i + 1;
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printItems(items, itemCount);

    greedyKnapsack(items, itemCount, capacity);

    return 0;
}