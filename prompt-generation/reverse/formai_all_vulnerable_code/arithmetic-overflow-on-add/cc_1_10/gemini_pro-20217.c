//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to calculate the optimal boot time
int opt_boot_time(int n, int m, int *arr, int **dp) {
    // Base cases
    if (n <= 0) {
        return 0;
    }
    if (m <= 0) {
        return -1;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    // Recursive cases
    int min_time;
    if (arr[n - 1] <= m) {
        min_time = opt_boot_time(n - 1, m - arr[n - 1], arr, dp);
         if (min_time != -1) {
             min_time += arr[n - 1];
         }
    }
    min_time = opt_boot_time(n, m, arr, dp);

    // Store the result in the DP table
    dp[n][m] = min_time;

    // Return the minimum boot time
    return min_time;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Create a DP table to store the results
    int **dp = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (m + 1));
        memset(dp[i], -1, sizeof(int) * (m + 1));
    }

    // Calculate and print the optimal boot time
    int min_time = opt_boot_time(n, m, arr, dp);
    if (min_time == -1) {
        printf("Impossible\n");
    } else {
        printf("%d\n", min_time);
    }

    // Free the allocated memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(arr);

    return 0;
}