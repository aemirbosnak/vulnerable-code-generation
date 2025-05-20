//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_W 10000

typedef struct Item {
    int id;
    int weight;
    int value;
} Item;

void readData(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &items[i].id, &items[i].weight, &items[i].value);
    }
}

void printItems(Item items[], int n) {
    printf("Items:\n");
    for (int i = 0; i < n; i++) {
        printf("ID %d: Weight %d, Value %d\n", items[i].id, items[i].weight, items[i].value);
    }
}

void printResult(int capacity, Item items[], int n) {
    int selectedItems[MAX_N];
    int numItems = 0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity && (numItems == 0 || items[i].value > items[numItems - 1].value)) {
            selectedItems[numItems++] = i;
            capacity -= items[i].weight;
        }
    }

    printf("\nSelected Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("ID %d\n", items[selectedItems[i]].id);
    }

    printf("\nTotal Value: %d\n", items[selectedItems[numItems - 1]].value + capacity * items[selectedItems[numItems - 1]].value / items[selectedItems[numItems - 1]].weight);
}

int main() {
    Item items[MAX_N];
    int n, w;

    scanf("%d%d", &n, &w);
    readData(items, n);
    printItems(items, n);

    printResult(w, items, n);

    return 0;
}