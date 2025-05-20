//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000

typedef struct {
    int weight;
    int value;
} Item;

void knapsack(Item items[], int n, int capacity);
int max(int a, int b);

int main() {
    int n, capacity, i;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[MAX_ITEMS];

    printf("Enter the weight and value of each item: \n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsack(items, n, capacity);

    return 0;
}

void knapsack(Item items[], int n, int capacity) {
    int i, j, weight;
    int table[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else if (items[i-1].weight <= j) {
                table[i][j] = max(items[i-1].value + table[i-1][j-items[i-1].weight], table[i-1][j]);
            } else {
                table[i][j] = table[i-1][j];
            }
        }
    }

    printf("Knapsack table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    printf("\nSelected items:\n");
    i = n;
    weight = capacity;
    while (i > 0 && weight > 0) {
        if (table[i][weight] != table[i-1][weight]) {
            printf("Item %d: weight = %d, value = %d\n", i, items[i-1].weight, items[i-1].value);
            weight -= items[i-1].weight;
        }
        i--;
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}