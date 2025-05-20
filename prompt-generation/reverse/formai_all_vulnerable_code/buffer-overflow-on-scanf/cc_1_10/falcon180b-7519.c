//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int value;
    int weight;
} Item;

int main() {
    int n, i, j;
    Item items[MAX_ITEMS];
    int knapsack_capacity = 50;

    printf("Welcome to the Greedy Algorithm Knapsack Problem!\n");
    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d:\n", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int max_value = 0;
    int knapsack_weight = 0;
    int current_index = 0;

    for (i = 0; i < n; i++) {
        if (items[i].value > max_value) {
            max_value = items[i].value;
            current_index = i;
        }
    }

    for (i = 0; i < n; i++) {
        if (items[i].value == max_value) {
            if (items[i].weight > items[current_index].weight) {
                current_index = i;
            }
        }
    }

    items[current_index].weight += knapsack_capacity - knapsack_weight;
    knapsack_weight += items[current_index].weight;

    printf("\nThe maximum value is %d and the corresponding items are:\n", max_value);

    for (i = 0; i < n; i++) {
        if (items[i].value == max_value) {
            printf("Item %d: Value = %d, Weight = %d\n", i + 1, items[i].value, items[i].weight);
        }
    }

    return 0;
}