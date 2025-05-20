//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100
#define MAX_VALUE 100

typedef struct {
    int weight;
    int value;
} Item;

Item items[MAX_ITEMS];
int num_items;
int capacity;

int compare_items(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->value / item2->weight) - (item1->value / item1->weight);
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < num_items; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &items[i].value);
    }

    qsort(items, num_items, sizeof(Item), compare_items);

    int total_weight = 0;
    int total_value = 0;
    for (int i = 0; i < num_items; i++) {
        if (total_weight + items[i].weight <= capacity) {
            total_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining_capacity = capacity - total_weight;
            total_value += remaining_capacity * (items[i].value / items[i].weight);
            break;
        }
    }

    printf("Total weight: %d\n", total_weight);
    printf("Total value: %d\n", total_value);

    return 0;
}