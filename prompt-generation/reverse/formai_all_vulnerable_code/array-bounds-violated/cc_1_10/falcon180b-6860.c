//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value of an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the optimal solution for knapsack problem using greedy algorithm
int knapSack(int W, int wt[], int val[], int n) {
    int i = 0, k = 0;

    // Sort the array in non-increasing order of ratio of value to weight
    for (int j = 0; j < n - 1; j++) {
        for (int l = 0; l < n - j - 1; l++) {
            if (wt[l] * val[l] > wt[l + 1] * val[l + 1]) {
                int temp = wt[l];
                wt[l] = wt[l + 1];
                wt[l + 1] = temp;
                int temp1 = val[l];
                val[l] = val[l + 1];
                val[l + 1] = temp1;
            }
        }
    }

    // Apply greedy algorithm to find the optimal solution
    for (int j = 0; j < n; j++) {
        if (wt[j] <= W) {
            W -= wt[j];
            k += val[j];
        }
    }
    return k;
}

// Main function to test the above functions
int main() {
    int W = 50, n = 7;
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };

    // Adding more elements to the array
    int i;
    for (i = 0; i < n - 3; i++) {
        val[i + 3] = findMax(val, i + 3) + 1;
        wt[i + 3] = rand() % 50 + 1;
    }

    printf("Maximum value of array: %d\n", findMax(val, n));

    printf("Optimal solution for knapsack problem: %d\n", knapSack(W, wt, val, n));

    return 0;
}