//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to find the maximum sum of a subarray with at most k elements
int max_subarray_sum(int arr[], int n, int k) {
    int max_sum = 0;
    int curr_sum = 0;

    // Initialize the first k elements as the maximum subarray sum
    for (int i = 0; i < k; i++) {
        curr_sum += arr[i];
        max_sum = curr_sum > max_sum? curr_sum : max_sum;
    }

    // Update the maximum subarray sum as we move along the array
    for (int i = k; i < n; i++) {
        curr_sum += arr[i] - arr[i-k];
        max_sum = curr_sum > max_sum? curr_sum : max_sum;
    }

    return max_sum;
}

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    // Fill the array with random integers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Enter the size of the subarray: ");
    scanf("%d", &k);

    // Find the maximum sum of a subarray with at most k elements
    int max_sum = max_subarray_sum(arr, n, k);

    printf("The maximum sum of a subarray with at most %d elements is %d\n", k, max_sum);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}