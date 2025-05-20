//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ITEMS 100

typedef struct {
    int value;
    int weight;
} Item;

int main() {
    int numItems;
    Item items[MAX_NUM_ITEMS];
    int maxValue = 0;

    // Read in the number of items
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    // Read in the value and weight of each item
    for (int i = 0; i < numItems; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        if (items[i].value > maxValue) {
            maxValue = items[i].value;
        }
    }

    // Sort the items in descending order of value-to-weight ratio
    for (int i = 0; i < numItems; i++) {
        for (int j = i + 1; j < numItems; j++) {
            if ((double)items[i].value / items[i].weight < (double)items[j].value / items[j].weight) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Initialize the knapsack with the first item
    int knapsackValue = items[0].value;
    int knapsackWeight = items[0].weight;

    // Iterate through the remaining items
    for (int i = 1; i < numItems; i++) {
        // If the current item has a higher value-to-weight ratio than the current knapsack,
        // replace the current knapsack with the current item
        if ((double)items[i].value / items[i].weight > (double)knapsackValue / knapsackWeight) {
            knapsackValue = items[i].value;
            knapsackWeight = items[i].weight;
        }
    }

    printf("The maximum value that can be obtained is %d.\n", knapsackValue);

    return 0;
}