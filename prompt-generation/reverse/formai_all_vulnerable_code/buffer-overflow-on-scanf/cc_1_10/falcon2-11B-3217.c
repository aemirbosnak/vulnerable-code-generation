//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100
#define MAX_ITEMS 50

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return itemA->value > itemB->value;
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    // Read in the items and their weights and values
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        int weight, value;
        printf("Enter the weight and value for item %d: ", i + 1);
        scanf("%d %d", &weight, &value);
        items[i] = (Item){weight, value};
    }

    // Sort the items by value-to-weight ratio
    qsort(items, numItems, sizeof(Item), compare);

    // Solve the Knapsack problem
    int capacity = 0;
    int value = 0;
    int selectedItems = 0;

    for (int i = 0; i < numItems; i++) {
        Item item = items[i];

        // Check if the item can be added to the knapsack
        if (item.weight <= capacity) {
            // Add the item to the knapsack
            value += item.value;
            capacity -= item.weight;
            selectedItems++;
        }
    }

    // Print the selected items and their total value
    printf("Selected items: ");
    for (int i = 0; i < selectedItems; i++) {
        Item item = items[i];
        printf("%d ", item.value);
    }
    printf("\nTotal value: %d\n", value);

    return 0;
}