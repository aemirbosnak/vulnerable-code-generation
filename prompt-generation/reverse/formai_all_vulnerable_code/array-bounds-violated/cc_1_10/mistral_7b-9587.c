//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

typedef struct {
    int id;
    int value;
    int weight;
} Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void knapsack(Item items[], int capacity, int n) {
    int i, w;
    Item result[n];

    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight && items[i].value > 0) {
            result[i] = items[i];
            capacity -= items[i].weight;
        }
    }

    for (i = n - 1; i >= 0 && capacity > 0; i--) {
        if (capacity >= items[i].weight) {
            result[i].value += result[i + 1].value;
            result[i].weight += result[i + 1].weight;
            free(result + (i + 1));
            n--;
            i--;
        }
    }

    printf("Selected items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: weight = %d, value = %d\n", result[i].id, result[i].weight, result[i].value);
    }

    printf("Total value: %d\n", eval_items(result, n));
}

int eval_items(Item items[], int n) {
    int i, sum = 0;

    for (i = 0; i < n; i++) {
        sum += items[i].value;
    }

    return sum;
}

void init_items(Item items[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        items[i].id = i + 1;
        items[i].value = rand() % 100;
        items[i].weight = rand() % 50 + 50;
    }
}

int main() {
    Item items[MAX_ITEMS];
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    init_items(items, n);

    knapsack(items, capacity, n);

    return 0;
}