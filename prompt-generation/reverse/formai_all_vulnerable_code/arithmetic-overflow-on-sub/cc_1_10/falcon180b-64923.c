//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int weight;
} Item;

void greedyAlgorithm(Item items[], int n, int capacity) {
    int i, j, maxValue = 0, maxIndex = 0;

    for (i = 0; i < n; i++) {
        if (items[i].value > maxValue) {
            maxValue = items[i].value;
            maxIndex = i;
        }
    }

    printf("Selected item %d with value %d\n", maxIndex, maxValue);

    capacity -= items[maxIndex].weight;

    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity && items[i].value > 0) {
            printf("Selected item %d with value %d\n", i, items[i].value);
            capacity -= items[i].weight;
        }
    }
}

int main() {
    Item items[MAX_SIZE];
    int n, i, j, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the details of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Selected items using greedy algorithm:\n");
    greedyAlgorithm(items, n, capacity);

    return 0;
}