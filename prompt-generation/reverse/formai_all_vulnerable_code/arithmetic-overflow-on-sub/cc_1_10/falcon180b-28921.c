//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int n, i, j, sum = 0;
    int items[MAX_SIZE];
    int values[MAX_SIZE];
    int knapsack_capacity = 50;
    int max_value = 0;

    // Generate random items
    srand(time(0));
    for (i = 0; i < n; i++) {
        items[i] = rand() % 10;
        values[i] = rand() % 50 + 1;
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    // Sort items by value/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (values[j] / items[j] > values[i] / items[i]) {
                int temp_items = items[i];
                items[i] = items[j];
                items[j] = temp_items;

                int temp_values = values[i];
                values[i] = values[j];
                values[j] = temp_values;
            }
        }
    }

    // Greedy algorithm to fill the knapsack
    for (i = 0; i < n; i++) {
        if (knapsack_capacity >= items[i]) {
            sum += values[i];
            knapsack_capacity -= items[i];
        }
    }

    printf("Total value: %d\n", sum);

    return 0;
}