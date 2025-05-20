//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int *values = malloc(n * sizeof(int));
    int *weights = malloc(n * sizeof(int));

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }

    int max_value = 0;
    for (int i = 0; i < n; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    int knapsack_capacity = max_value;
    int *knapsack_contents = malloc(MAX_SIZE * sizeof(int));

    int knapsack_size = 0;
    int knapsack_value = 0;

    for (int i = 0; i < n; i++) {
        if (weights[i] <= knapsack_capacity) {
            if (knapsack_size >= MAX_SIZE) {
                printf("Knapsack is full!\n");
                break;
            }
            knapsack_contents[knapsack_size++] = i;
            knapsack_value += values[i];
            knapsack_capacity -= weights[i];
        } else {
            int j;
            for (j = 0; j < knapsack_size; j++) {
                if (weights[i] - weights[knapsack_contents[j]] <= knapsack_capacity) {
                    knapsack_contents[j] = i;
                    knapsack_value += values[i] - values[knapsack_contents[j]];
                    knapsack_capacity -= weights[i] - weights[knapsack_contents[j]];
                    break;
                }
            }
        }
    }

    printf("Items in knapsack: ");
    for (int i = 0; i < knapsack_size; i++) {
        printf("%d ", knapsack_contents[i]);
    }
    printf("\nTotal value: %d\n", knapsack_value);

    free(values);
    free(weights);
    free(knapsack_contents);

    return 0;
}