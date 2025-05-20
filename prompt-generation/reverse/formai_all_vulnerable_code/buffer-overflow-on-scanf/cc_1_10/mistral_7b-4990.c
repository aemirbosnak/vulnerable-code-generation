//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000
#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    int value;
    int weight;
} Item;

void print_items(Item items[], int n) {
    printf("POST-APOCALYPTIC KNAPSACK\n");
    printf("--------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d kg, %d value\n", items[i].name, items[i].weight, items[i].value);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int n, i, w, capacity = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for item %d:\n", i + 1);
        scanf("%s %d %d", items[i].name, &items[i].weight, &items[i].value);
        capacity += items[i].weight;
    }

    print_items(items, n);

    int knapsack[MAX_WEIGHT + 1];
    memset(knapsack, 0, sizeof(knapsack));

    for (i = 0; i < n; i++) {
        for (w = items[i].weight; w <= capacity; w++) {
            if (knapsack[w - items[i].weight] + items[i].value > knapsack[w]) {
                knapsack[w] = knapsack[w - items[i].weight] + items[i].value;
            }
        }
    }

    printf("\nMaximum value: %d\n", knapsack[capacity]);

    return 0;
}