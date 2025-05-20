//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// A utility function to find the maximum value in an integer array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// A utility function to find the minimum value in an integer array
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// A greedy algorithm to solve the fractional knapsack problem
void fractionalKnapsack(int W, int wt[], int val[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (wt[i] <= W) {
            W -= wt[i];
            val[i] += W * wt[i] / wt[i];
        }
    }
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    fractionalKnapsack(W, wt, val, n);
    printf("The maximum value that can be obtained is: %d\n", val[0]);
    return 0;
}