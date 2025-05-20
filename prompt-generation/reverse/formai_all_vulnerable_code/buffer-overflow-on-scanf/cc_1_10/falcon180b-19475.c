//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum sum subarray with constraints
int maxSumSubarray(int arr[], int k, int n) {
    int max_sum = 0;
    int curr_sum = 0;
    int start_index = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        // Add the current element to the current sum
        curr_sum += arr[i];

        // If the current sum exceeds k, remove the first element of the subarray
        if (curr_sum > k) {
            curr_sum -= arr[start_index];
            start_index++;
        }

        // Update the maximum sum if necessary
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    return max_sum;
}

int main() {
    int n, k;

    // Get the size of the array and the constraint value
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the constraint value: ");
    scanf("%d", &k);

    // Allocate memory for the array
    int *arr = (int *) malloc(n * sizeof(int));

    // Get the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the maxSumSubarray function and print the result
    int max_sum = maxSumSubarray(arr, k, n);
    printf("The maximum sum subarray with constraint %d is %d\n", k, max_sum);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}