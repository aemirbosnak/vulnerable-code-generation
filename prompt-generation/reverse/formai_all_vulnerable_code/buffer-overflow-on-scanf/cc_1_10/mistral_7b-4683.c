//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_W 50

typedef struct {
    int id;
    int weight;
    int value;
} Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    Item *x = (Item *)a;
    Item *y = (Item *)b;
    return (x->value > y->value) ? -1 : 1;
}

int knapSack(int W, Item items[], int n) {
    int K[n + 1][W + 1];
    int i, w;

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (items[i - 1].weight <= w)
                K[i][w] = (items[i - 1].value + K[i - 1][w - items[i - 1].weight]) > K[i - 1][w] ? (items[i - 1].value + K[i - 1][w - items[i - 1].weight]) : K[i - 1][w];
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n;
    Item items[MAX_N];
    int i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &items[i].id, &items[i].weight, &items[i].value);
    }

    qsort(items, n, sizeof(Item), compare);

    printf("Items: ");
    for (i = 0; i < n; i++)
        printf("%d ", items[i].id);

    printf("\nValues: ");
    for (i = 0; i < n; i++)
        printf("%d ", items[i].value);

    printf("\n\nCapacity: %d", MAX_W);
    printf("\nTotal Value: %d\n", knapSack(MAX_W, items, n));

    return 0;
}