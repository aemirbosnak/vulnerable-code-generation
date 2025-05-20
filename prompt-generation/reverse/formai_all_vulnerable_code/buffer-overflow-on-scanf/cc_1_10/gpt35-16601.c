//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

// Structure to hold an item's value and weight
typedef struct {
    int value;
    int weight;
} item;

// Function to sort items in decreasing order based on value/weight ratio
int cmp(const void *p1, const void *p2)
{
    item *item1 = (item*) p1;
    item *item2 = (item*) p2;
    double ratio1 = (double) item1->value / item1->weight;
    double ratio2 = (double) item2->value / item2->weight;
    return ratio2 > ratio1 ? 1 : -1;
}

// Function to calculate the maximum value that can be obtained with the given capacity
int knapsack(int capacity, item items[], int n)
{
    // Sort items in decreasing order based on value/weight ratio
    qsort(items, n, sizeof(item), cmp);

    int max_value = 0;
    int total_weight = 0;
    int i = 0;

    // Fill the knapsack with items until it is full or all items are used
    while (total_weight < capacity && i < n) {
        // Try to add the next item
        int remaining_capacity = capacity - total_weight;
        int item_weight = items[i].weight;
        int item_value = items[i].value;
        if (item_weight <= remaining_capacity) {
            max_value += item_value;
            total_weight += item_weight;
        } else {
            // Item does not fit completely, add a fraction of it
            max_value += item_value * ((double) remaining_capacity / item_weight);
            total_weight += remaining_capacity;
        }
        i++;
    }

    return max_value;
}

int main()
{
    int capacity, n, i;
    item items[MAX_ITEMS];

    printf("Enter knapsack capacity:\n");
    scanf("%d", &capacity);

    printf("Enter number of items:\n");
    scanf("%d", &n);

    printf("Enter items (value, weight):\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int max_value = knapsack(capacity, items, n);

    printf("Maximum value that can be obtained is %d\n", max_value);

    return 0;
}