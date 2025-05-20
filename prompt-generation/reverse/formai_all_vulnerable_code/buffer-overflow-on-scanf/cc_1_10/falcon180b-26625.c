//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int weight;
    char name[20];
} Item;

void knapsack(Item *items, int n, int capacity) {
    int i, j;
    int max_value = 0;
    int knapsack_value = 0;
    int *selected_items = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        selected_items[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < capacity + 1; j++) {
            if (j >= items[i].weight) {
                if (items[i].value + knapsack_value > max_value) {
                    max_value = items[i].value + knapsack_value;
                }
            }
        }
    }

    printf("Maximum value that can be obtained: %d\n", max_value);

    for (i = 0; i < n; i++) {
        if (items[i].value + knapsack_value == max_value) {
            printf("%s ", items[i].name);
        }
    }

    printf("\n");
}

int main() {
    int n, i;
    Item items[MAX_SIZE];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the details of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &items[i].value);

        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);

        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsack(items, n, capacity);

    return 0;
}