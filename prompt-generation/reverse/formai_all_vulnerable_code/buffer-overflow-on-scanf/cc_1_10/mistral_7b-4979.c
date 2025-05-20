//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int id;
    int weight;
    int value;
} Item;

int main() {
    int n, capacity;
    Item items[MAX];
    int i, w, j, included[MAX];
    int maxValue = 0;

    scanf("%d %d", &n, &capacity);

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &items[i].id, &items[i].weight, &items[i].value);
    }

    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            w = items[i].weight;
            included[i] = 1;
            maxValue += items[i].value;
            capacity -= w;
        }
    }

    for (j = n - 1; j >= 0 && capacity > 0; j--) {
        if (items[j].weight <= capacity) {
            w = items[j].weight;
            included[j] = 1;
            maxValue += items[j].value;
            capacity -= w;
        }
    }

    printf("Maximum value: %d\n", maxValue);
    printf("Items included:\n");
    for (i = 0; i < n; i++) {
        if (included[i] == 1) {
            printf("%d ", items[i].id);
        }
    }

    return 0;
}