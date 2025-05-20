//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_WEIGHT 100
#define MAX_VALUE 100

struct item {
    int weight;
    int value;
};

void print_knapsack(struct item items[], int n, int capacity) {
    int i, j;

    printf("Weight\t\t\tValue\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t\t%d\n", items[i].weight, items[i].value);
    }
    printf("\n");

    for (j = 0; j < MAX_VALUE; j++) {
        int max_value = 0;
        for (i = 0; i < n; i++) {
            if (items[i].weight <= j && j - items[i].weight >= capacity) {
                max_value = items[i].value;
            }
        }
        printf("%d\t\t\t%d\n", j, max_value);
    }
}

int main() {
    int items[MAX_ITEMS][2];
    int n, capacity, max_value;
    int i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and values of items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i][0], &items[i][1]);
    }

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &capacity);

    max_value = 0;
    for (j = 0; j < capacity; j++) {
        int max_value = 0;
        for (i = 0; i < n; i++) {
            if (items[i][0] <= j && j - items[i][0] >= capacity) {
                max_value = items[i][1];
            }
        }
        if (max_value > max_value) {
            max_value = max_value;
        }
    }

    printf("Maximum value that can be achieved: %d\n", max_value);

    print_knapsack(items, n, capacity);

    return 0;
}