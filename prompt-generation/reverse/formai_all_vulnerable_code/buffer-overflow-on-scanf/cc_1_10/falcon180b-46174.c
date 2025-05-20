//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
    int max = arr[0]; // Initialize the maximum value to the first element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) { // If the current element is greater than the maximum value, update the maximum value
            max = arr[i];
        }
    }
    return max;
}

// Function to implement the greedy algorithm for the fractional knapsack problem
int fractionalKnapsack(int W, int wt[], int val[], int n) {
    int i, j;
    int totalValue = 0; // Initialize the total value to zero
    for (i = 0; i < n; i++) {
        // Find the maximum value that can be obtained by considering the current item
        int maxValue = (W - wt[i]) / wt[i] * val[i];
        // Update the total value and the remaining capacity of the knapsack
        totalValue += maxValue;
        W -= wt[i];
        // If the item cannot fit in the knapsack, move on to the next item
        if (W <= 0) {
            break;
        }
    }
    return totalValue;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }

    int W;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int totalValue = fractionalKnapsack(W, wt, val, n);
    printf("The maximum value that can be obtained is %d\n", totalValue);

    return 0;
}