//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int index;
} Item;

void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    const Item* itemA = (const Item*)a;
    const Item* itemB = (const Item*)b;

    if (itemA->value > itemB->value) {
        return 1;
    } else if (itemA->value < itemB->value) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int n, W;
    scanf("%d %d", &n, &W);

    Item items[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].index);
    }

    qsort(items, n, sizeof(Item), compare);

    int knapsackCapacity = 0;
    int knapsackValue = 0;

    for (int i = 0; i < n; i++) {
        if (knapsackCapacity + items[i].value <= W) {
            knapsackCapacity += items[i].value;
            knapsackValue += items[i].value;
        } else {
            int remainingCapacity = W - knapsackCapacity;
            if (items[i].value <= remainingCapacity) {
                knapsackCapacity = W;
                knapsackValue += items[i].value;
            }
        }
    }

    printf("Knapsack capacity: %d\n", knapsackCapacity);
    printf("Knapsack value: %d\n", knapsackValue);

    return 0;
}