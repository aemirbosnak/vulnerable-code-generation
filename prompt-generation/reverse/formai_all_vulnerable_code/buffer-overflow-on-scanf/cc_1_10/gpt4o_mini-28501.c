//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    float value;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return (itemB->value < itemA->value) - (itemB->value > itemA->value);
}

void greedyKnapsack(int capacity, int n, int weights[], int values[]) {
    Item *items = malloc(n * sizeof(Item));
    
    for (int i = 0; i < n; i++) {
        if (weights[i] <= 0) {
            printf("Invalid weight for item %d\n", i);
            free(items);
            return;
        }
        items[i].index = i;
        items[i].value = (float)values[i] / weights[i];
    }

    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity <= 0) break;

        int itemIndex = items[i].index;
        if (weights[itemIndex] <= capacity) {
            totalValue += values[itemIndex];
            capacity -= weights[itemIndex];
            printf("Taking full item %d (Weight: %d, Value: %d)\n", itemIndex, weights[itemIndex], values[itemIndex]);
        } else {
            float fraction = (float)capacity / weights[itemIndex];
            totalValue += values[itemIndex] * fraction;
            printf("Taking %f of item %d (Weight: %d, Value: %d)\n", fraction, itemIndex, weights[itemIndex], values[itemIndex]);
            capacity = 0;
        }
    }
    printf("Maximum value in Knapsack: %f\n", totalValue);
    free(items);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int *weights = malloc(n * sizeof(int));
    int *values = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i);
        scanf("%d %d", &weights[i], &values[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    greedyKnapsack(capacity, n, weights, values);

    free(weights);
    free(values);
    
    return 0;
}