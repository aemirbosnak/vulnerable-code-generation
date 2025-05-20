//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 100
#define MAX_VALUE 100

int main() {
    int n, i, j, k, value[MAX_VALUE], weight[MAX_VALUE];
    double ratio[MAX_VALUE], max_ratio = 0;
    int knap_size, capacity;
    int *selected;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &knap_size);

    for (i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i+1);
        scanf("%d %d", &value[i], &weight[i]);
        if (weight[i] > knap_size) {
            printf("Item %d is too heavy!\n", i+1);
            exit(0);
        }
        ratio[i] = (double)value[i] / (double)weight[i];
        if (ratio[i] > max_ratio) {
            max_ratio = ratio[i];
        }
    }

    selected = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        selected[i] = 0;
    }

    capacity = knap_size;
    for (i = n-1; i >= 0 && capacity > 0; i--) {
        if (selected[i] == 0 && weight[i] <= capacity) {
            selected[i] = 1;
            capacity -= weight[i];
        }
    }

    printf("The selected items are: ");
    for (i = 0; i < n; i++) {
        if (selected[i] == 1) {
            printf("%d ", i+1);
        }
    }
    printf("\n");

    return 0;
}