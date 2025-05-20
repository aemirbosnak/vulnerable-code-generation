//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum sum of a subarray
int max_sum_subarray(int arr[], int n) {
    int max_sum = arr[0];
    int curr_sum = arr[0];

    for (int i = 1; i < n; i++) {
        curr_sum += arr[i];
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    return max_sum;
}

// Function to find the maximum sum of a subarray using greedy algorithm
int max_sum_subarray_greedy(int arr[], int n) {
    int max_sum = arr[0];
    int curr_sum = arr[0];

    for (int i = 1; i < n; i++) {
        curr_sum += arr[i];
        if (curr_sum < 0) {
            curr_sum = 0;
        }
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

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
    printf("Maximum sum of a subarray: %d\n", max_sum);

    max_sum = max_sum_subarray_greedy(arr, n);
    printf("Maximum sum of a subarray using greedy algorithm: %d\n", max_sum);

    return 0;
}