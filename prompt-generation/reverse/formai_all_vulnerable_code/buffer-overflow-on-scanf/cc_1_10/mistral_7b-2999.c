//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 100
#define MAX_WEIGHT 1000

typedef struct {
    int id;
    int weight;
    int value;
} Item;

int main() {
    Item items[MAX_ITEMS];
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter %d items' details:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &items[i].id, &items[i].weight, &items[i].value);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    // Sort items in decreasing order of value per unit weight
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].value / items[j].weight > items[j + 1].value / items[j + 1].weight) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    int included_items = 0;
    int current_weight = 0;
    int total_value = 0;

    for (int i = 0; i < n && current_weight < W; i++) {
        if (current_weight + items[i].weight <= W) {
            total_value += items[i].value;
            current_weight += items[i].weight;
            included_items++;
        }
    }

    printf("Items included: %d\n", included_items);
    printf("Total value: %d\n", total_value);

    return 0;
}