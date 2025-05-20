//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int id;
    int weight;
    int value;
    float ratio; // value to weight ratio
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return (itemB->ratio < itemA->ratio) - (itemB->ratio > itemA->ratio);
}

void print_items(Item items[], int n) {
    printf("Items:\n");
    printf("ID | Weight | Value | Value/Weight Ratio\n");
    for (int i = 0; i < n; i++) {
        printf("%2d | %6d | %5d | %.3f\n", items[i].id, items[i].weight, items[i].value, items[i].ratio);
    }
}

void maximize_value(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);

    int totalValue = 0;
    printf("\nSherlock's haul:\n");
    printf("Chosen Items:\n");

    for (int i = 0; i < n; i++) {
        if (capacity <= 0)
            break; // No more capacity left

        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
            printf("Item ID: %d (Weight: %d, Value: %d) - Fully included.\n", items[i].id, items[i].weight, items[i].value);
        } else {
            float fraction = (float)capacity / items[i].weight;
            totalValue += (int)(items[i].value * fraction);
            printf("Item ID: %d (Weight: %d, Value: %d) - Partially included (%.2f)\n", items[i].id, items[i].weight, items[i].value, fraction);
            break; // We've filled the bag
        }
    }

    printf("Total value of stolen items recovered: %d\n", totalValue);
}

int main() {
    int n, capacity;
    
    printf("Welcome to the Sherlock Holmes Item Recovery Program.\n");
    printf("Enter the number of stolen items: ");
    scanf("%d", &n);

    Item *items = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight; // Calculate value/weight ratio
    }

    printf("Enter the capacity of the bag: ");
    scanf("%d", &capacity);

    print_items(items, n);
    maximize_value(items, n, capacity);

    free(items);
    return 0;
}