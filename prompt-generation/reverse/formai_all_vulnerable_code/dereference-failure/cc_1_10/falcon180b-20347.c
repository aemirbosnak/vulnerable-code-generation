//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to implement the Greedy algorithm for the fractional knapsack problem
int fractionalKnapsack(int val[], int wt[], int W, int n) {
    int i, w;
    float ratio;

    // Sort the items in decreasing order of value/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (w = i + 1; w < n; w++) {
            if ((float)val[w] / wt[w] > (float)val[i] / wt[i]) {
                int temp = val[i];
                val[i] = val[w];
                val[w] = temp;
                wt[i] = wt[w];
                wt[w] = wt[i];
            }
        }
    }

    // Calculate the maximum value that can be obtained using the given weight limit
    int maxValue = 0;
    for (i = 0; i < n; i++) {
        if (wt[i] <= W) {
            maxValue += val[i];
        } else {
            ratio = (float)W / wt[i];
            maxValue += ratio * val[i];
            break;
        }
    }

    return maxValue;
}

int main() {
    int n, W, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter the values and weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }

    int maxValue = fractionalKnapsack(val, wt, findMax(wt, n), n);
    printf("Maximum value that can be obtained: %d\n", maxValue);

    return 0;
}