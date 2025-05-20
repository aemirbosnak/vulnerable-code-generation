//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 20

struct item {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
    int weight;
    int value_per_weight;
};

void print_item(struct item* item) {
    printf("%s (%d) - $%d\n", item->name, item->weight, item->value_per_weight);
}

int compare_value_per_weight(const void* a, const void* b) {
    struct item* item1 = (struct item*)a;
    struct item* item2 = (struct item*)b;

    return item2->value_per_weight - item1->value_per_weight;
}

int main() {
    int num_items;
    scanf("%d", &num_items);

    struct item* items = malloc(num_items * sizeof(struct item));

    for (int i = 0; i < num_items; i++) {
        scanf("%s %s %d", items[i].name, items[i].value, &items[i].weight);
        items[i].value_per_weight = atoi(items[i].value);
    }

    qsort(items, num_items, sizeof(struct item), compare_value_per_weight);

    int knapsack_capacity = 50;
    int total_value = 0;

    for (int i = 0; i < num_items; i++) {
        if (items[i].weight <= knapsack_capacity) {
            total_value += items[i].value_per_weight;
            knapsack_capacity -= items[i].weight;
        } else {
            int remaining_capacity = knapsack_capacity;
            while (remaining_capacity > 0 && i < num_items - 1 && items[i].value_per_weight < items[i + 1].value_per_weight) {
                remaining_capacity -= items[i].weight;
                i++;
            }

            if (remaining_capacity > 0) {
                total_value += items[i].value_per_weight;
                knapsack_capacity = 0;
            } else {
                break;
            }
        }
    }

    printf("Total value: $%d\n", total_value);

    return 0;
}