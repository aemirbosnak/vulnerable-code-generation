//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_COINS 1000
#define MAX_ITEMS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int weight;
    int value;
} Item;

int compare_items(const void *a, const void *b) {
    const Item *item_a = a;
    const Item *item_b = b;
    if (item_a->value / item_a->weight > item_b->value / item_b->weight) {
        return 1;
    } else if (item_a->value / item_a->weight < item_b->value / item_b->weight) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int num_items;
    scanf("%d", &num_items);
    Item items[MAX_ITEMS];
    for (int i = 0; i < num_items; i++) {
        scanf("%s %d %d", items[i].name, &items[i].weight, &items[i].value);
    }
    qsort(items, num_items, sizeof(Item), compare_items);
    int num_coins;
    scanf("%d", &num_coins);
    int capacity = num_coins * 100;
    int knapsack_value = 0;
    int knapsack_weight = 0;
    for (int i = 0; i < num_items; i++) {
        if (knapsack_weight + items[i].weight <= capacity) {
            knapsack_value += items[i].value;
            knapsack_weight += items[i].weight;
        } else {
            int j = 0;
            while (j < i && knapsack_weight + items[j].weight <= capacity) {
                knapsack_value -= items[j].value;
                knapsack_weight -= items[j].weight;
                j++;
            }
            knapsack_value += items[i].value;
            knapsack_weight += items[i].weight;
        }
    }
    printf("%d\n", knapsack_value);
    return 0;
}