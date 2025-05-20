//Code Llama-13B DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
/*
 * Greedy Algorithms: Paranoid Style
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

struct Item {
    int value;
    int weight;
};

int main() {
    int n, capacity;
    struct Item items[MAX_ITEMS];

    srand(time(NULL));

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        items[i].value = rand() % 100 + 1;
        items[i].weight = rand() % 100 + 1;
    }

    // Sort the items in descending order of value-to-weight ratio
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].value * items[i].weight < items[j].value * items[j].weight) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Greedily fill the knapsack
    int totalValue = 0, totalWeight = 0;
    for (int i = 0; i < n && totalWeight < capacity; i++) {
        int remainingCapacity = capacity - totalWeight;
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            totalWeight += items[i].weight;
        } else {
            totalValue += items[i].value * (remainingCapacity / items[i].weight);
            totalWeight += remainingCapacity;
        }
    }

    printf("Total value: %d\n", totalValue);
    printf("Total weight: %d\n", totalWeight);

    return 0;
}