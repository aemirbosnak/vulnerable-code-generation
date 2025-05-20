//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAPACITY 100

int main() {
    int n, m;
    int value[MAX_CAPACITY], weight[MAX_CAPACITY];
    int i, j, k;
    int knapsack_capacity, total_weight;
    int max_profit = 0;
    int profit[MAX_CAPACITY];
    int selected_items[MAX_CAPACITY];
    int item_count = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &knapsack_capacity);

    for (i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d:\n", i+1);
        scanf("%d %d", &value[i], &weight[i]);
        profit[i] = (value[i] * weight[i]) / 100;
    }

    srand(time(NULL));
    for (k = 0; k < 10; k++) {
        for (i = 0; i < n; i++) {
            selected_items[i] = 0;
        }
        total_weight = 0;
        for (j = 0; j < n; j++) {
            if (total_weight + weight[j] <= knapsack_capacity) {
                selected_items[j] = 1;
                total_weight += weight[j];
            }
        }
        max_profit = 0;
        for (j = 0; j < n; j++) {
            if (selected_items[j] == 1) {
                max_profit += profit[j];
            }
        }
        if (max_profit > 0) {
            item_count++;
            printf("Solution %d:\n", item_count);
            for (j = 0; j < n; j++) {
                if (selected_items[j] == 1) {
                    printf("Item %d selected, profit = %d\n", j+1, profit[j]);
                }
            }
            printf("Total profit = %d\n\n", max_profit);
        }
    }

    return 0;
}