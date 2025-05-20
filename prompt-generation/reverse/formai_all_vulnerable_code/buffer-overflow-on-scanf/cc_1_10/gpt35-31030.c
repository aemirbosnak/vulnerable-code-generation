//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    int value;
    int weight;
} item_t;

int cmpfunc(const void* a, const void* b) {
    item_t* ia = (item_t*)a;
    item_t* ib = (item_t*)b;
    return (ib->value / ib->weight) - (ia->value / ia->weight);
}

int knapsack(int capacity, item_t items[], int num_items) {
    int i, total_value = 0;
    double ratio;
    qsort(items, num_items, sizeof(item_t), cmpfunc);
    for (i = 0; i < num_items; i++) {
        if (capacity == 0) {
            break;
        }
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            ratio = (double)capacity / items[i].weight;
            total_value += items[i].value * ratio;
            capacity = 0;
        }
    }
    return total_value;
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    printf("The maximum value that can be obtained is: %d\n", knapsack(capacity, items, num_items));
    return 0;
}