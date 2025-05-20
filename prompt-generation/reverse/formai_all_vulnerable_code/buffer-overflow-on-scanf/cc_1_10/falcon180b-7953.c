//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int weight;
} Item;

void greedyAlgorithm(Item items[], int n, int capacity) {
    int i, j;
    int totalWeight = 0;
    int totalValue = 0;

    // Sort the items in descending order of value-to-weight ratio
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[j].value / items[j].weight > items[i].value / items[i].weight) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            break;
        }
    }

    printf("Total value: %d\n", totalValue);
}

int main() {
    Item items[MAX_SIZE];
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: value = ", i + 1);
        scanf("%d", &items[i].value);
        printf("weight = ");
        scanf("%d", &items[i].weight);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    greedyAlgorithm(items, n, capacity);

    return 0;
}