//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000

// Function to find the maximum value of a given array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to implement the greedy algorithm for the fractional knapsack problem
int fractionalKnapsack(int val[], int wt[], int n, int W) {
    int i, j;
    int knap[MAX_N];
    for (i = 0; i < n; i++) {
        knap[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = W; j >= wt[i]; j--) {
            if (val[i] * (j - wt[i]) > knap[j]) {
                knap[j] = val[i] * (j - wt[i]);
            }
        }
    }
    return knap[W];
}

// Main function to test the greedy algorithm
int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);
    int maxVal = findMax(val, n);
    int knapVal = fractionalKnapsack(val, wt, n, W);
    printf("Maximum value: %d\n", maxVal);
    printf("Value of knapsack: %d\n", knapVal);
    return 0;
}