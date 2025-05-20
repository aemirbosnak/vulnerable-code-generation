//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>

// Constants
#define MAX_N 100000
#define MAX_W 1000000000

// Input and output
int n, w;
int weights[MAX_N];
int values[MAX_N];

// Solution
int best_weight = 0;
int best_value = 0;

// Greedy algorithm
void greedy() {
    // Sort the items by their value-to-weight ratio in decreasing order.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((double)values[i] / weights[i] < (double)values[j] / weights[j]) {
                int temp1 = weights[i];
                int temp2 = values[i];
                weights[i] = weights[j];
                values[i] = values[j];
                weights[j] = temp1;
                values[j] = temp2;
            }
        }
    }

    // Iterate through the items in the sorted order.
    int current_weight = 0;
    int current_value = 0;
    for (int i = 0; i < n; i++) {
        // If adding the current item would not exceed the weight limit, add it to the solution.
        if (current_weight + weights[i] <= w) {
            current_weight += weights[i];
            current_value += values[i];
        }
    }

    // Update the best solution if the current solution is better.
    if (current_value > best_value) {
        best_weight = current_weight;
        best_value = current_value;
    }
}

// Main function
int main() {
    // Read the input.
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    // Run the greedy algorithm.
    greedy();

    // Print the output.
    printf("%d %d\n", best_weight, best_value);

    return 0;
}