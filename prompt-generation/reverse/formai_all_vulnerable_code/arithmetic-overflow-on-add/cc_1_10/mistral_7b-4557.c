//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void swap(Item* a, Item* b) {
    Item temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Item arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j].value / arr[j].weight > arr[min_idx].value / arr[min_idx].weight)
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void printItem(Item item) {
    printf("Item %d, Weight: %d, Value: %d\n", item.id, item.weight, item.value);
}

void printKnapsack(int capacity, Item items[], int n) {
    int i;
    int W;

    printf("Capacity: %d\n", capacity);
    printf("Items in Knapsack:\n");

    W = capacity;
    for (i = 0; i < n; i++) {
        if (W >= items[i].weight && items[i].value > 0) {
            W -= items[i].weight;
            items[i].value = 0;
            printf("Add Item %d, Weight: %d, Value: %d\n", items[i].id, items[i].weight, items[i].value);
        }
    }
}

void knapSack(int capacity, Item items[], int n) {
    int i, W;
    int K[n + 1][capacity + 1];

    for (i = 0; i <= n; i++) {
        for (W = 0; W <= capacity; W++) {
            if (i == 0 || W == 0)
                K[i][W] = 0;
            else if (items[i - 1].weight <= W)
                K[i][W] = max(K[i - 1][W], items[i - 1].value + K[i - 1][W - items[i - 1].weight]);
            else
                K[i][W] = K[i - 1][W];
        }
    }

    printKnapsack(capacity, items, n);
    printf("Maximum Value: %d\n", K[n][capacity]);
}

int main() {
    int n, capacity;
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    for (i = 0; i < n; i++) {
        printf("Enter Item %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &items[i].id);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
        printf("Value: ");
        scanf("%d", &items[i].value);
        printf("\n");
    }

    printf("Enter Knapsack Capacity: ");
    scanf("%d", &capacity);

    selectionSort(items, n);
    knapSack(capacity, items, n);

    return 0;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}