//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
// The Puzzle of the Lost Treasure

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int knapsack(int W, int *wt, int *val, int n) {
    int i, w;
    int K[n+1][W+1];

    for(i = 0; i <= n; i++) {
        for(w = 0; w <= W; w++) {
            if(i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if(wt[i-1] <= w) {
                K[i][w] = (val[i-1] + K[i-1][w-wt[i-1]]) > K[i-1][w] ? (val[i-1] + K[i-1][w-wt[i-1]]) : K[i-1][w];
            }
            else {
                K[i][w] = K[i-1][w];
            }
        }
    }

    return K[n][W];
}

int main() {
    int i, n, maxWeight, result;
    int *weights, *values;

    printf("Welcome to the Puzzle of the Lost Treasure!\n\n");

    printf("You are on a treasure hunt! You have to carry a maximum of weight of 50 units with you.\n");
    printf("There are several treasures in this dungeon, each with its own weight and value.\n\n");

    printf("Enter the number of treasures: ");
    scanf("%d", &n);

    weights = (int*)malloc(n * sizeof(int));
    values = (int*)malloc(n * sizeof(int));

    printf("\nEnter the weight and value of each treasure:\n");
    for(i = 0; i < n; i++) {
        printf("\nTreasure %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &weights[i]);
        printf("Value: ");
        scanf("%d", &values[i]);
    }

    printf("\nCalculating the maximum value of treasures you can carry...\n\n");

    maxWeight = 50;
    result = knapsack(maxWeight, weights, values, n);

    printf("You can carry treasures with a maximum total value of %d.\n\n", result);
    printf("Good luck on your treasure hunt!\n\n");

    free(weights);
    free(values);

    return 0;
}