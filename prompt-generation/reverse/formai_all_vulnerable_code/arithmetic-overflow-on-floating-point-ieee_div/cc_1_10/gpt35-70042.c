//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define our struct to hold the items
typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

// Compare function for qsort
int cmpfunc(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    if (itemA->ratio > itemB->ratio) {
        return -1;
    }
    else if (itemA->ratio < itemB->ratio) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int n, capacity, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the maximum capacity: ");
    scanf("%d", &capacity);

    // Allocate memory for our array of items
    Item *items = (Item *)malloc(sizeof(Item) * n);

    // Ask for user input for each item
    for (i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d (separated by space): ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Sort the items by their ratio (greedy step)
    qsort(items, n, sizeof(Item), cmpfunc);

    int currentWeight = 0;
    float totalValue = 0;

    // Loop through the sorted items
    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // We can add the entire item to our knapsack
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else {
            // We can only add a fraction of the item to our knapsack
            int remainingCapacity = capacity - currentWeight;
            totalValue += remainingCapacity * items[i].ratio;
            break;
        }
    }

    printf("The maximum value we can obtain is %.2f\n", totalValue);

    // Free up the memory used by the array
    free(items);

    return 0;
}