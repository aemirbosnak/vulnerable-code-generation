//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Welcome to the Greedy Algorithm!\n");
    printf("Enter the number of items you have: ");
    scanf("%d", &n);

    int *weights = (int*) malloc(n * sizeof(int));
    int *values = (int*) malloc(n * sizeof(int));

    printf("Enter the weight and value of each item, separated by a space:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    int capacity;
    printf("Enter the maximum weight capacity of your bag: ");
    scanf("%d", &capacity);

    int *taken = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        taken[i] = 0;
    }

    int total_value = 0;
    int current_weight = 0;

    while (current_weight < capacity) {
        int best_item = -1;
        double best_ratio = -1;

        for (int i = 0; i < n; i++) {
            if (taken[i] == 0) {
                double ratio = (double) values[i] / weights[i];
                if (ratio > best_ratio) {
                    best_ratio = ratio;
                    best_item = i;
                }
            }
        }

        if (best_item == -1) {
            break;
        }

        taken[best_item] = 1;
        current_weight += weights[best_item];
        total_value += values[best_item];

        printf("Added item %d with weight %d and value %d to the bag!\n", best_item+1, weights[best_item], values[best_item]);
    }

    printf("Final result: Bag with a total weight of %d and a total value of %d.\n", current_weight, total_value);

    free(weights);
    free(values);
    free(taken);

    return 0;
}