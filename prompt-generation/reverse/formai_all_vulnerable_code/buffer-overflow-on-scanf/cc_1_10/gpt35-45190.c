//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    float ratioA = ((Item *) a)->ratio;
    float ratioB = ((Item *) b)->ratio;
    return (ratioB > ratioA) - (ratioB < ratioA);
}

float knapsack(int capacity, Item *items, int numItems) {
    float totalValue = 0;
    int i;

    for (i = 0; i < numItems; i++) {
        items[i].ratio = (float) items[i].value / (float) items[i].weight;
    }

    qsort(items, numItems, sizeof(Item), compare);

    for (i = 0; i < numItems; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            float fraction = (float) capacity / (float) items[i].weight;
            totalValue += items[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    int i, numItems, capacity;
    float value;
    Item items[100];

    printf("Enter the number of items:\n");
    scanf("%d", &numItems);

    printf("Enter the capacity of the knapsack:\n");
    scanf("%d", &capacity);

    for (i = 0; i < numItems; i++) {
        printf("Enter the value and weight of item %d:\n", i + 1);
        scanf("%f %d", &value, &items[i].weight);
        items[i].value = (int) value;
    }

    float maxValue = knapsack(capacity, items, numItems);

    printf("The maximum value that can be put in a knapsack of capacity %d is %.2f\n", capacity, maxValue);

    return 0;
}