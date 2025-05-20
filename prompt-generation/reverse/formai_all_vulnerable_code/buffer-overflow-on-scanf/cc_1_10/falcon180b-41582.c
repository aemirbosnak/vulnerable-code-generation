//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, max_sum = 0;
    int arr[MAX_SIZE], dp[MAX_SIZE][MAX_SIZE];

    // Read the size of the array
    scanf("%d", &n);

    // Read the elements of the array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize the dynamic programming table
    for (i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // Fill the dynamic programming table
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i][j-1] + arr[i-1];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
            if (dp[i][j] > max_sum) {
                max_sum = dp[i][j];
            }
        }
    }

    // Print the maximum sum and the corresponding subarray
    printf("The maximum sum of a subarray is %d\n", max_sum);
    printf("The subarray is [");
    for (i = max_sum; i < n; i++) {
        printf("%d ", arr[i-1]);
    }
    printf("]\n");

    return 0;
}