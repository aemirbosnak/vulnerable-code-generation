//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int value;
    int weight;
    int index;
};

void swap(struct node* a, struct node* b) {
    struct node temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    struct node nodeA = *(struct node*)a;
    struct node nodeB = *(struct node*)b;

    if (nodeA.value > nodeB.value) {
        return 1;
    } else if (nodeA.value < nodeB.value) {
        return -1;
    } else {
        return 0;
    }
}

void knapSack(int W, int wt[], int val[], int n) {
    struct node items[n];

    for (int i = 0; i < n; i++) {
        items[i].value = val[i];
        items[i].weight = wt[i];
        items[i].index = i;
    }

    qsort(items, n, sizeof(struct node), compare);

    int k = 0;
    int totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            totalValue += (W * items[i].value) / items[i].weight;
            break;
        }
    }

    printf("Total value of items: %d\n", totalValue);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n];
    int wt[n];

    printf("Enter the values and weights of items:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }

    int W;
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);

    knapSack(W, wt, val, n);

    return 0;
}