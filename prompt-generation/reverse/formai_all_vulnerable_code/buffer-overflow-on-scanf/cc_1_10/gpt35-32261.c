//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>

// Define a struct to hold the items we will be selecting from
struct item {
    int value;
    int weight;
};

// Define our compare function for sorting items by value-to-weight ratio
int cmp(const void *a, const void *b) {
    struct item *item_a = (struct item *)a;
    struct item *item_b = (struct item *)b;
    float ratio_a = (float)item_a->value / item_a->weight;
    float ratio_b = (float)item_b->value / item_b->weight;
    return ratio_b > ratio_a ? 1 : -1;
}

// Our main function will read in a list of items and a maximum weight, and output the optimal combination of items to reach that weight
int main() {
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    struct item items[num_items];

    // Read in the items, asking for their value and weight
    for (int i = 0; i < num_items; i++) {
        printf("Item %d value: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Item %d weight: ", i + 1);
        scanf("%d", &items[i].weight);
    }

    // Sort the items by their value-to-weight ratio
    qsort(items, num_items, sizeof(struct item), cmp);

    int max_weight;
    printf("Enter the maximum weight: ");
    scanf("%d", &max_weight);

    int taken[num_items];
    for (int i = 0; i < num_items; i++) {
        taken[i] = 0;
    }

    int total_value = 0;
    int current_weight = 0;

    // Start selecting items in order of highest value-to-weight ratio
    for (int i = 0; i < num_items && current_weight < max_weight; i++) {
        if (items[i].weight + current_weight <= max_weight) {
            taken[i] = 1;
            total_value += items[i].value;
            current_weight += items[i].weight;
        }
    }

    printf("Optimal combination of items: ");
    for (int i = 0; i < num_items; i++) {
        if (taken[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\nTotal value: %d", total_value);

    return 0;
}