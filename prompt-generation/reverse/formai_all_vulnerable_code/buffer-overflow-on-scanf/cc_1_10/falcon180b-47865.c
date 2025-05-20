//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the maximum sum subarray
int max_sum_subarray(int arr[], int n) {
    int max_sum = 0;
    int curr_sum = 0;
    int start_index = 0;
    int end_index = 0;

    // Initialize the starting and ending indices
    start_index = 0;
    end_index = 0;

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // Update the current sum
        curr_sum += arr[i];

        // If the current sum is greater than the maximum sum so far,
        // update the maximum sum and the starting and ending indices
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            start_index = end_index;
            end_index = i;
        }

        // If the current sum is negative, reset the current sum
        if (curr_sum < 0) {
            curr_sum = 0;
            start_index = end_index = i + 1;
        }
    }

    // Return the maximum sum and the starting and ending indices
    return max_sum;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = max_sum_subarray(arr, n);
    printf("Maximum sum subarray: %d\n", max_sum);

    return 0;
}