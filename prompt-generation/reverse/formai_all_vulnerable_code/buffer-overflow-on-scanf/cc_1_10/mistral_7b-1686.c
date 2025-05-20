//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int weight;
    int value;
} Item;

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

Item items[MAX_ITEMS];
int n;
int W;

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("\nEnter item details:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &items[i].id, &items[i].weight, &items[i].value);
    }

    printf("\nEnter knapsack capacity: ");
    scanf("%d", &W);

    printf("\nSelected items and total value:\n");
    int i = 0, j = 0, num_items = 0;
    while (i < n && j < W) {
        if (items[i].weight <= W - items[j].weight) {
            W -= items[i].weight;
            printf("Item %d (Weight %d, Value %d)\n", items[i].id, items[i].weight, items[i].value);
            num_items++;
            i++;
        } else {
            printf("Item %d (Weight %d, Value %d) skipped\n", items[j].id, items[j].weight, items[j].value);
            j++;
            i++;
        }
    }

    if (num_items < n) {
        for (; j < W; j++) {
            printf("Item %d (Weight %d, Value %d) added\n", items[i - 1].id, items[i - 1].weight, items[i - 1].value);
            num_items++;
        }
    }

    printf("Total value: %d\n", num_items * items[i - 1].value);

    return 0;
}