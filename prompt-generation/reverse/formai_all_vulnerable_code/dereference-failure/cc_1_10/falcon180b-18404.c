//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum sum of a subarray
int max_subarray_sum(int arr[], int n) {
    int max_sum = arr[0];
    int curr_sum = arr[0];

    // Traverse through the array
    for (int i = 1; i < n; i++) {
        // If the current element is greater than the current sum,
        // update the current sum
        if (arr[i] > curr_sum) {
            curr_sum = arr[i];
        }
        // Otherwise, reset the current sum to the current element
        else {
            curr_sum = arr[i];
        }

        // Update the maximum sum if the current sum is greater
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    return max_sum;
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum sum of a subarray
    int max_sum = max_subarray_sum(arr, n);

    // Print the maximum sum
    printf("The maximum sum of a subarray is: %d\n", max_sum);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}