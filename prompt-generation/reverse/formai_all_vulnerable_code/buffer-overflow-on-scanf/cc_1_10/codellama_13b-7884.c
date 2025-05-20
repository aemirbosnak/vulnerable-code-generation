//Code Llama-13B DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
// Greedy Algorithms Example Program

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int n, m, i, j, k, cost, maxCost = 0;
    int arr[100][100], dp[100][100];

    // Take input
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the number of roads: ");
    scanf("%d", &m);

    // Initialize arrays
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[i][j] = 0;
            dp[i][j] = 0;
        }
    }

    // Take input for roads
    for (i = 0; i < m; i++) {
        printf("Enter the cost of road %d: ", i + 1);
        scanf("%d", &cost);
        arr[i][i] = cost;
    }

    // Fill the dp array
    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = arr[i][j] + dp[i - 1][j];
            }
        }
    }

    // Find the maximum cost
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dp[i][j] > maxCost) {
                maxCost = dp[i][j];
            }
        }
    }

    // Print the result
    printf("The maximum cost is: %d\n", maxCost);

    return 0;
}