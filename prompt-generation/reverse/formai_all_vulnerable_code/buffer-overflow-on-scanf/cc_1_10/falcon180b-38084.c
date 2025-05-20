//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int weight;
} item;

int compare(const void* a, const void* b) {
    item* item1 = (item*)a;
    item* item2 = (item*)b;

    if (item1->value / item1->weight > item2->value / item2->weight) {
        return 1;
    } else if (item1->value / item1->weight < item2->value / item2->weight) {
        return -1;
    } else {
        return 0;
    }
}

void knapSack(int capacity, int n, item arr[]) {
    int w[n], i, j;

    for (i = 0; i < n; i++) {
        w[i] = arr[i].weight;
    }

    qsort(w, n, sizeof(int), compare);

    int value = 0;
    for (i = n - 1, j = 0; i >= 0 && capacity > 0; i--) {
        if (w[i] <= capacity) {
            value += arr[i].value;
            capacity -= w[i];
        } else {
            int k = capacity / w[i];
            value += k * arr[i].value;
            capacity -= k * w[i];
            break;
        }
    }

    printf("Maximum value obtained: %d\n", value);
}

int main() {
    int n, i;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    item arr[n];

    printf("Enter the value and weight of each item:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    int capacity;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapSack(capacity, n, arr);

    return 0;
}