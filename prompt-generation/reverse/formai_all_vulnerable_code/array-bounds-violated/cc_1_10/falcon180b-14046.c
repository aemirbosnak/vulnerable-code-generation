//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array
int min(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to implement the greedy algorithm for the fractional knapsack problem
void fractionalKnapsack(int W, int n, int wt[], int val[], int w[], int nw) {
    int i = 0;
    int currW = 0;
    int currVal = 0;
    while (i < n && currW < W) {
        if (wt[i] <= currW + w[i - 1]) {
            currW += wt[i];
            currVal += val[i];
        }
        i++;
    }
    printf("Maximum value that can be obtained: %d\n", currVal);
}

int main() {
    int n, W, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);
    int w[n];
    w[0] = 0;
    for (i = 1; i < n; i++) {
        w[i] = w[i - 1] + wt[i - 1];
    }
    printf("The maximum value that can be obtained is: ");
    fractionalKnapsack(W, n, wt, val, w, n);
    return 0;
}