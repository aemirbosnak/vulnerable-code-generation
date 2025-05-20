//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_CAPACITY 20

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void selection(Item items[], int size, int capacity) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        int index = i;
        for (j = i + 1; j < size; j++) {
            if ((items[j].weight < capacity) && (items[j].value > items[index].value)) {
                index = j;
            }
        }
        if (index != i) {
            swap(&items[i], &items[index]);
        }
    }
}

void knapsack(Item items[], int size, int capacity) {
    int i, j, w;
    int result[size];

    selection(items, size, capacity);

    for (i = size - 1, w = capacity; i >= 0; i--) {
        if (items[i].weight <= w) {
            result[--size] = items[i].id;
            w -= items[i].weight;
        }
    }

    printf("Selected items: ");
    for (i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\nTotal value: %d\n", items[0].value + (size > 0 ? items[result[0]].value : 0));
}

int main() {
    Item items[MAX_ITEMS] = {
        {.id = 1, .weight = 3, .value = 4},
        {.id = 2, .weight = 4, .value = 5},
        {.id = 3, .weight = 1, .value = 2},
        {.id = 4, .weight = 5, .value = 6},
        {.id = 5, .weight = 2, .value = 3},
        {.id = 6, .weight = 3, .value = 5},
        {.id = 7, .weight = 4, .value = 7},
        {.id = 8, .weight = 2, .value = 6},
        {.id = 9, .weight = 1, .value = 1},
        {.id = 10, .weight = 6, .value = 8}
    };

    knapsack(items, sizeof(items) / sizeof(items[0]), MAX_CAPACITY);

    return 0;
}