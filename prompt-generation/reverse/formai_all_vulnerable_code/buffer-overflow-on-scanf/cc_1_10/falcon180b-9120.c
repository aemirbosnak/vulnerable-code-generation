//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int n, i, j;
    int *arr;
    int *dp;
    int max_sum;

    // Initialize random seed
    srand(time(NULL));

    // Get input size
    printf("Enter the size of the input array: ");
    scanf("%d", &n);

    // Allocate memory for the input array
    arr = (int *)malloc(n * sizeof(int));

    // Initialize the input array with random integers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Allocate memory for the dynamic programming array
    dp = (int *)malloc(n * sizeof(int));

    // Initialize the dynamic programming array
    for (i = 0; i < n; i++) {
        dp[i] = arr[i];
    }

    // Compute the maximum sum using the dynamic programming approach
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
        if (dp[i] > max_sum) {
            max_sum = dp[i];
        }
    }

    // Print the maximum sum
    printf("The maximum sum is: %d\n", max_sum);

    // Free memory
    free(arr);
    free(dp);

    return 0;
}