//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

typedef struct item {
    int value;
    int weight;
} Item;

int compare(const void *a, const void *b) {
    Item *ia = (Item *)a;
    Item *ib = (Item *)b;
    return (ib->value / ib->weight) - (ia->value / ia->weight);
}

int main() {
    int num_items, max_weight, i;
    Item items[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the maximum weight: ");
    scanf("%d", &max_weight);

    printf("Enter the value and weight of each item:\n");

    for (i = 0; i < num_items; i++) {
        printf("Item %d: ", i+1);
        scanf("%d%d", &items[i].value, &items[i].weight);
    }

    qsort(items, num_items, sizeof(Item), compare);

    int current_weight = 0;
    int current_value = 0;

    for (i = 0; i < num_items; i++) {
        if (current_weight + items[i].weight <= max_weight) {
            current_weight += items[i].weight;
            current_value += items[i].value;
        } else {
            int remaining_weight = max_weight - current_weight;
            current_value += (int)(items[i].value * ((double)remaining_weight / items[i].weight));
            break;
        }
    }

    printf("The maximum value that can be obtained is %d\n", current_value);

    return 0;
}