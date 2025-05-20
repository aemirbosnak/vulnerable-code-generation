//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int weight;
} item_t;

int compare_items(const void *a, const void *b) {
    item_t *item1 = (item_t *)a;
    item_t *item2 = (item_t *)b;
    if (item1->value / item1->weight > item2->value / item2->weight) {
        return -1;
    } else if (item1->value / item1->weight < item2->value / item2->weight) {
        return 1;
    } else {
        return 0;
    }
}

void knapsack(item_t items[], int n, int capacity) {
    qsort(items, n, sizeof(item_t), compare_items);
    int knap[MAX_SIZE] = {0};
    int i = 0;
    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            knap[items[i].value] += items[i].value;
        } else {
            int j;
            for (j = items[i].value; j <= capacity; j++) {
                if (knap[j]!= 0) {
                    knap[j] -= knap[j - items[i].weight];
                }
            }
            capacity -= items[i].weight;
        }
    }
    printf("Knapsack capacity: %d\n", capacity);
}

int main() {
    item_t items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    knapsack(items, n, capacity);
    return 0;
}