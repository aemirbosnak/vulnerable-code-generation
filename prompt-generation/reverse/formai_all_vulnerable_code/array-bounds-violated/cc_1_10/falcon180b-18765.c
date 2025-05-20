//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int value;
    int weight;
} Item;

void generateItems(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].value = rand() % 100;
        items[i].weight = rand() % 20 + 1;
    }
}

int compareItems(const void *a, const void *b) {
    return (*(Item *) a).value - (*(Item *) b).value;
}

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    for (i = 0; i <= W; i++) {
        w = 0;
        for (int j = 0; j < n; j++) {
            if (wt[j] <= i) {
                w += val[j];
            }
        }
        if (w > 0) {
            return w;
        }
    }
    return 0;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);

    Item items[n];
    generateItems(items, n);

    qsort(items, n, sizeof(Item), compareItems);

    printf("\nItem\tValue\tWeight\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, items[i].value, items[i].weight);
    }

    int maxValue = knapSack(W, items[0].weight, items[0].value, n);

    printf("\nMaximum value that can be obtained: %d\n", maxValue);

    return 0;
}