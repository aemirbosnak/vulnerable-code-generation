//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

typedef struct {
    int weight;
    int value;
} Item;

int cmp(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    double value1 = (double)item1->value / item1->weight;
    double value2 = (double)item2->value / item2->weight;

    if (value1 > value2) {
        return -1;
    } else if (value1 < value2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_items;
    Item items[MAX_ITEMS];
    int capacity;

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    printf("Enter items (weight, value):\n");
    for (int i = 0; i < num_items; i++) {
        scanf("%d%d", &items[i].weight, &items[i].value);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    qsort(items, num_items, sizeof(Item), cmp);

    int current_weight = 0;
    double current_value = 0;
    for (int i = 0; i < num_items; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            current_value += items[i].value;
        } else {
            int remaining_capacity = capacity - current_weight;
            current_value += remaining_capacity * ((double)items[i].value / items[i].weight);
            break;
        }
    }

    printf("Maximum value = %lf\n", current_value);

    return 0;
}