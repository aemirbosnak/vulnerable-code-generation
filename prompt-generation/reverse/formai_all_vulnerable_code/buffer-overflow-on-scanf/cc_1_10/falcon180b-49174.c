//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int weight;
} Item;

void generateRandomItems(Item items[], int numItems) {
    srand(time(NULL));
    for (int i = 0; i < numItems; i++) {
        items[i].value = rand() % MAX_SIZE;
        items[i].weight = rand() % MAX_SIZE;
    }
}

int compareItems(const void* a, const void* b) {
    const Item* itemA = (const Item*)a;
    const Item* itemB = (const Item*)b;
    if (itemA->value / itemA->weight > itemB->value / itemB->weight) {
        return 1;
    } else if (itemA->value / itemA->weight < itemB->value / itemB->weight) {
        return -1;
    } else {
        return 0;
    }
}

void greedyAlgorithm(Item items[], int numItems, int knapsackCapacity) {
    qsort(items, numItems, sizeof(Item), compareItems);

    int totalValue = 0;
    int knapsackWeight = 0;

    for (int i = 0; i < numItems; i++) {
        if (knapsackWeight + items[i].weight <= knapsackCapacity) {
            totalValue += items[i].value;
            knapsackWeight += items[i].weight;
        } else {
            break;
        }
    }

    printf("Total value: %d\n", totalValue);
}

int main() {
    Item items[MAX_SIZE];
    int numItems;

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    generateRandomItems(items, numItems);

    printf("Enter knapsack capacity: ");
    scanf("%d", &numItems);

    greedyAlgorithm(items, numItems, numItems);

    return 0;
}