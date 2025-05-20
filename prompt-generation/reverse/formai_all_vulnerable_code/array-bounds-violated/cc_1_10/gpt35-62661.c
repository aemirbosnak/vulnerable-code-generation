//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>

int main() {
    printf("I am so excited to show you my unique Greedy Algorithm program!\n");
    printf("Let's jump right into it!\n");

    int n, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];
    printf("Enter the weight and value of each item:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &value[i]);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int used[n];
    for (i = 0; i < n; i++) {
        used[i] = 0;
    }

    int total_value = 0, current_weight = 0, j;
    while (current_weight < capacity) {
        int best_item = -1;
        double best_value_per_weight = 0;

        for (j = 0; j < n; j++) {
            if (used[j] == 0) {
                double value_per_weight = (double) value[j] / weight[j];
                if (value_per_weight > best_value_per_weight) {
                    best_value_per_weight = value_per_weight;
                    best_item = j;
                }
            }
        }

        used[best_item] = 1;
        current_weight += weight[best_item];
        total_value += value[best_item];
    }

    printf("The items selected in the knapsack are:\n");
    for (i = 0; i < n; i++) {
        if (used[i]) {
            printf("Item %d (weight %d, value %d)\n", i + 1, weight[i], value[i]);
        }
    }
    printf("The total value of the items in the knapsack is: %d\n", total_value);

    return 0;
}