//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int index;
    int value;
} Item;

int compare(const void *a, const void *b) {
    Item *ia = (Item *) a;
    Item *ib = (Item *) b;
    if (ia->value > ib->value) {
        return 1;
    } else if (ia->value < ib->value) {
        return -1;
    } else {
        return 0;
    }
}

void greedyAlgorithm(int n, int *values, int *weights, int W) {
    int i, j;
    Item *items = (Item *) malloc(n * sizeof(Item));
    for (i = 0; i < n; i++) {
        items[i].index = i;
        items[i].value = values[i];
    }
    qsort(items, n, sizeof(Item), compare);
    int sum = 0;
    for (i = 0; i < n && W > 0; i++) {
        if (W >= weights[items[i].index]) {
            sum += values[items[i].index];
            W -= weights[items[i].index];
        } else {
            break;
        }
    }
    printf("Greedy Algorithm result: %d\n", sum);
    free(items);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int *values = (int *) malloc(n * sizeof(int));
    int *weights = (int *) malloc(n * sizeof(int));
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);
    greedyAlgorithm(n, values, weights, W);
    return 0;
}