//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 101
#define MAX_WEIGHT 10001

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void print_items(Item items[], int n) {
    printf("Items:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d: [%d, %d]\n", items[i].id, items[i].weight, items[i].value);
    }
}

void knapsack_greedy(Item items[], int n, int capacity) {
    int selected[MAX_ITEMS] = {0};
    Item max_value_item;

    for (int i = 0; i < n && capacity > 0; ++i) {
        if (items[i].weight <= capacity) {
            selected[items[i].id] = 1;
            capacity -= items[i].weight;
            if (i + 1 < n && items[i + 1].value / items[i + 1].weight > max_value_item.value / max_value_item.weight) {
                max_value_item = items[i + 1];
            }
        }
    }

    printf("Selected items:\n");
    for (int i = 1; i <= MAX_ITEMS; ++i) {
        if (selected[i]) {
            printf("%d ", i);
        }
    }
    printf("\nTotal value: %d\n", max_value_item.value);
}

int main() {
    Item items[MAX_ITEMS] = {0};
    int n;

    printf("Number of items: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        items[i].id = i;
        printf("Item %d details:\n", i);
        scanf("%d%d%d", &items[i].weight, &items[i].value, &items[i].value);
    }

    int capacity;

    printf("Knapsack capacity: ");
    scanf("%d", &capacity);

    print_items(items, n);
    knapsack_greedy(items, n, capacity);

    return 0;
}