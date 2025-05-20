//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>

#define MAX_ITEMS 1000

struct Item {
    int value;
    int weight;
};

typedef struct Item Item;

int compare_items(const void* a, const void* b) {
    Item* item_a = (Item*) a;
    Item* item_b = (Item*) b;

    double ratio_a = (double) item_a->value / item_a->weight;
    double ratio_b = (double) item_b->value / item_b->weight;

    if (ratio_a == ratio_b) {
        return 0;
    } else if (ratio_a > ratio_b) {
        return -1;
    } else {
        return 1;
    }
}

int knapsack(Item* items, int num_items, int capacity) {
    qsort(items, num_items, sizeof(Item), compare_items);

    int total_value = 0;
    int current_weight = 0;
    int i;

    for (i = 0; i < num_items; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining_capacity = capacity - current_weight;
            total_value += remaining_capacity * ((double) items[i].value / items[i].weight);
            break;
        }
    }

    return total_value;
}

int main() {
    Item items[MAX_ITEMS];
    int num_items, capacity;

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    int i;
    for (i = 0; i < num_items; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    int max_value = knapsack(items, num_items, capacity);

    printf("Maximum value of items that can be put into the knapsack is: %d\n", max_value);

    return 0;
}