//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int value;
    int weight;
} Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    return (*(Item *)a).value - (*(Item *)b).value;
}

int knapSack(int capacity, int n, Item items[]) {
    int i, j;
    int W[n + 1];
    int V[n + 1];

    for (i = 0; i <= n; i++) {
        W[i] = 0;
        V[i] = 0;
    }

    for (i = 0; i <= n; i++) {
        if (i <= capacity) {
            V[i] = items[i].value;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            if (items[i].value > items[j].value)
                V[i] = V[j] + items[i].value;
        }
    }

    for (i = n - 1; i >= 0; i--) {
        W[i] = V[i];
        for (j = i + 1; j <= n; j++) {
            if (items[i].value > items[j].value)
                W[i] = W[j] - items[i].value;
        }
    }

    return W[n];
}

int main() {
    int n, i;
    Item items[MAX_SIZE];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the item values and weights:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    qsort(items, n, sizeof(Item), compare);

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int maxValue = knapSack(capacity, n, items);

    printf("The maximum value that can be obtained is: %d\n", maxValue);

    return 0;
}