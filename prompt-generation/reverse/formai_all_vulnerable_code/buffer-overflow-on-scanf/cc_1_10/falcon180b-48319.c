//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_COINS 6
#define MAX_VALUE 1000

typedef struct {
    int value;
    int weight;
} Item;

void generateItems(Item items[], int numItems) {
    srand(time(NULL));
    for (int i = 0; i < numItems; i++) {
        items[i].value = rand() % MAX_VALUE + 1;
        items[i].weight = rand() % MAX_VALUE + 1;
    }
}

int compareItems(const void *a, const void *b) {
    const Item *itemA = (const Item *)a;
    const Item *itemB = (const Item *)b;

    if (itemA->value / itemA->weight > itemB->value / itemB->weight) {
        return -1;
    } else if (itemA->value / itemA->weight < itemB->value / itemB->weight) {
        return 1;
    } else {
        return 0;
    }
}

int knapSack(Item items[], int numItems, int capacity) {
    qsort(items, numItems, sizeof(Item), compareItems);

    int value = 0;
    int weight = 0;

    for (int i = 0; i < numItems; i++) {
        if (weight + items[i].weight <= capacity) {
            value += items[i].value;
            weight += items[i].weight;
        } else {
            int remainingCapacity = capacity - weight;
            value += items[i].value * (remainingCapacity / items[i].weight);
            break;
        }
    }

    return value;
}

int main() {
    int numItems;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    Item items[numItems];
    generateItems(items, numItems);

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int maxValue = knapSack(items, numItems, capacity);

    printf("The maximum value that can be obtained is: %d\n", maxValue);

    return 0;
}