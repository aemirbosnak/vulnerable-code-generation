//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value of a given array
int max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to implement the Greedy algorithm for the fractional knapsack problem
void fractionalKnapsack(int W, int wt[], int val[], int n) {
    int i, j;
    int knapW = 0, knapVal = 0;

    // Sort the items in decreasing order of value-to-weight ratio
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (val[i] / wt[i] < val[j] / wt[j]) {
                int temp = val[i];
                val[i] = val[j];
                val[j] = temp;
                temp = wt[i];
                wt[i] = wt[j];
                wt[j] = temp;
            }
        }
    }

    // Fill the knapsack with items in decreasing order of value-to-weight ratio
    for (i = 0; i < n; i++) {
        if (knapW + wt[i] <= W) {
            knapW += wt[i];
            knapVal += val[i];
        }
    }

    printf("Maximum value of the knapsack: %d\n", knapVal);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);
    fractionalKnapsack(W, wt, val, n);
    return 0;
}