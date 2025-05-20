//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VARIABLES 100
#define MAX_VALUES 1000

typedef struct {
    int value;
    int weight;
} item;

item items[MAX_VARIABLES];
int n;
int capacity;

void read_input() {
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
}

int compare(const void *a, const void *b) {
    item *item1 = (item *) a;
    item *item2 = (item *) b;

    if (item1->value / item1->weight > item2->value / item2->weight)
        return -1;
    else if (item1->value / item1->weight < item2->value / item2->weight)
        return 1;
    else
        return 0;
}

void sort_items() {
    qsort(items, n, sizeof(item), compare);
}

void knapsack() {
    int knapsack[MAX_VALUES] = {0};
    int w = 0;

    for (int i = 0; i < n; i++) {
        int u = items[i].value;
        int limit = capacity - w;

        if (u <= limit) {
            knapsack[w] += u;
            w += items[i].weight;
        } else {
            int frac = limit / items[i].weight;
            knapsack[w] += frac * items[i].value;
            w += frac * items[i].weight;
        }
    }

    printf("The maximum value that can be obtained is: %d\n", knapsack[capacity]);
}

int main() {
    read_input();
    sort_items();
    knapsack();

    return 0;
}