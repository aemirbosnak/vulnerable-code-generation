//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

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

void printSolution(Item items[], int n, int w) {
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= w) {
            printf("Item %d (Weight: %d, Value: %d)\n", items[i].id, items[i].weight, items[i].value);
            w -= items[i].weight;
        }
    }
}

int main() {
    Item items[MAX_N];
    int n, w;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &w);

    readData(items, n);

    // Sort items in decreasing order of value per unit weight
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].value / items[i].weight > items[j].value / items[j].weight) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Greedy algorithm
    int selectedItems = 0;
    for (int i = 0; i < n && w > 0; i++) {
        if (items[i].weight <= w) {
            printf("Item %d (Weight: %d, Value: %d)\n", items[i].id, items[i].weight, items[i].value);
            w -= items[i].weight;
            selectedItems++;
        }
    }

    // Print remaining items if any
    if (w > 0) {
        printf("The knapsack cannot be filled with the given items.\n");
    }

    printf("Total number of items selected: %d\n", selectedItems);

    return 0;
}