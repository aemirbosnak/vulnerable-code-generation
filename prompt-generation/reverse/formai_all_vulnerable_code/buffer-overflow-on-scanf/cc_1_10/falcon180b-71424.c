//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000
#define MAX_VALUE 1000

typedef struct {
    int value;
    int weight;
} Item;

int main() {
    int n, i, j, max_value = 0, curr_value = 0;
    Item items[MAX_ITEMS];

    // read input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        if (items[i].value > max_value) {
            max_value = items[i].value;
        }
    }

    // sort items by value/weight ratio in descending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[j].value / items[j].weight > items[i].value / items[i].weight) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // initialize knapsack with maximum value item
    curr_value = max_value;
    int knapsack[MAX_ITEMS];
    knapsack[0] = 0;
    int knapsack_index = 0;

    // fill knapsack with items in descending order of value/weight ratio
    for (i = 0; i < n; i++) {
        if (curr_value >= items[i].value) {
            curr_value -= items[i].value;
            knapsack[++knapsack_index] = items[i].weight;
        } else {
            break;
        }
    }

    // print knapsack contents
    printf("Knapsack contents:\n");
    for (i = 0; i <= knapsack_index; i++) {
        printf("%d ", knapsack[i]);
    }
    printf("\n");

    return 0;
}