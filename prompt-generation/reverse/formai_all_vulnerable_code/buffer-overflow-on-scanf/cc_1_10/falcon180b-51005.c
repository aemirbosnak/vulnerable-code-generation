//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Function to find the maximum sum of a subarray with given sum
int maxSubarraySum(int arr[], int n, int sum) {
    int max_sum = INT_MIN;
    int curr_sum = 0;
    int start = 0;
    int end = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];

        // If the current sum exceeds the given sum, reset the current sum
        if (curr_sum > sum) {
            curr_sum = arr[i];
            start = i + 1;
        }

        // Update the maximum sum if a new maximum is found
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            end = i;
        }
    }

    // Return the maximum sum and its starting and ending indices
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

    int sum;
    printf("Enter the target sum: ");
    scanf("%d", &sum);

    int max_sum = maxSubarraySum(arr, n, sum);

    if (max_sum == INT_MIN) {
        printf("No subarray found with given sum.\n");
    } else {
        printf("Maximum sum of a subarray with given sum %d is %d.\n", sum, max_sum);
        printf("Starting index: %d\n", max_sum - sum);
        printf("Ending index: %d\n", max_sum - 1);
    }

    return 0;
}