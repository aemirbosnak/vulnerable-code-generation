//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

typedef struct {
    int weight;
    int value;
} Item;

void readInput(Item items[MAX_ITEMS], int *numItems) {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(EXIT_FAILURE);
    }

    *numItems = 0;
    for (int i = 0; i < MAX_ITEMS && fscanf(file, "%d%d", &items[i].weight, &items[i].value) == 2; ++i) {
        (*numItems)++;
    }
    fclose(file);
}

void printSolution(Item items[MAX_ITEMS], int numItems, int capacity, int *selectedItems, int numSelected) {
    printf("Selected items:\n");
    for (int i = 0; i < numSelected; ++i) {
        int index = selectedItems[i];
        printf("Item %d: weight = %d, value = %d\n", index + 1, items[index].weight, items[index].value);
    }

    printf("Total value: %d\n", capacity * items[numSelected - 1].value + items[numSelected - 1].value);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems;
    int capacity;

    readInput(items, &numItems);

    if (numItems > MAX_ITEMS) {
        printf("Error: Too many items. Increase the MAX_ITEMS constant.\n");
        exit(EXIT_FAILURE);
    }

    scanf("%d", &capacity);

    int *selectedItems = calloc(numItems, sizeof(int));
    int numSelected = 0;

    for (int i = 0; i < numItems; ++i) {
        if (capacity >= items[i].weight) {
            selectedItems[numSelected++] = i;
            capacity -= items[i].weight;
        }
    }

    printSolution(items, numItems, capacity, selectedItems, numSelected);

    free(selectedItems);

    return EXIT_SUCCESS;
}