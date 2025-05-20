//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct item {
    int value;
    int weight;
} item;

int compare_items(const void *a, const void *b) {
    item *item1 = (item *)a;
    item *item2 = (item *)b;
    if (item1->value / item1->weight > item2->value / item2->weight) {
        return 1;
    } else if (item1->value / item1->weight == item2->value / item2->weight) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    srand(time(NULL));
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    item items[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        items[i].value = rand() % 100;
        items[i].weight = rand() % 100;
    }
    qsort(items, n, sizeof(item), compare_items);
    int total_value = 0;
    int total_weight = 0;
    for (int i = 0; i < n; i++) {
        if (total_weight + items[i].weight <= capacity) {
            total_value += items[i].value;
            total_weight += items[i].weight;
        } else {
            break;
        }
    }
    printf("The total value of the items in the knapsack is: %d\n", total_value);
    printf("The total weight of the items in the knapsack is: %d\n", total_weight);
    return 0;
}