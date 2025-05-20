//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000

// Structure to represent an item
struct Item {
    int weight;
    int value;
} items[MAX_ITEMS];

// Compare function for sorting items based on value/weight ratio in descending order
int compare(const void* a, const void* b) {
    double ratio_a = ((double) ((struct Item *) a)->value) / ((struct Item *) a)->weight;
    double ratio_b = ((double) ((struct Item *) b)->value) / ((struct Item *) b)->weight;

    return ratio_b - ratio_a;
}

int main() {
    int capacity, num_items, i;
    double total_value = 0;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the weight and value of the items:\n");
    for(i = 0; i < num_items; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    qsort(items, num_items, sizeof(struct Item), compare);

    for(i = 0; i < num_items; i++) {
        if(capacity >= items[i].weight) {
            // Take the whole item if it fits
            total_value += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take a fraction of the item if it doesn't fit whole
            total_value += ((double) capacity / items[i].weight) * items[i].value;
            break;
        }
    }

    printf("The maximum value that can be obtained is: %f\n", total_value);

    return 0;
}