//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_VALUE 1000

int main() {

    srand(time(NULL));
    int n = rand() % MAX_ITEMS + 1;
    int values[n];
    int weights[n];
    int capacity = rand() % MAX_VALUE + 1;

    printf("Number of items: %d\n", n);
    printf("Capacity of knapsack: %d\n", capacity);

    // Generate random values and weights for each item
    for (int i = 0; i < n; i++) {
        values[i] = rand() % MAX_VALUE + 1;
        weights[i] = rand() % MAX_VALUE + 1;
    }

    // Sort items in descending order of value-to-weight ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (values[j] / weights[j] > values[i] / weights[i]) {
                int temp_value = values[i];
                int temp_weight = weights[i];
                values[i] = values[j];
                weights[i] = weights[j];
                values[j] = temp_value;
                weights[j] = temp_weight;
            }
        }
    }

    // Initialize knapsack with first item
    int knapsack_value = 0;
    int knapsack_weight = 0;
    int item_index = 0;

    // Fill knapsack with items in descending order of value-to-weight ratio
    while (knapsack_weight + weights[item_index] <= capacity && item_index < n) {
        if (values[item_index] / weights[item_index] >= knapsack_value / knapsack_weight) {
            knapsack_value += values[item_index];
            knapsack_weight += weights[item_index];
            item_index++;
        } else {
            item_index++;
        }
    }

    printf("Knapsack value: %d\n", knapsack_value);
    printf("Knapsack weight: %d\n", knapsack_weight);

    return 0;
}