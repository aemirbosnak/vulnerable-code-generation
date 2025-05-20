//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Function to calculate the maximum sum of a subarray
int max_sum_subarray(int arr[], int n) {
    int max_sum = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    return max_sum;
}

// Function to find the maximum sum of a subarray using greedy algorithm
int max_sum_subarray_greedy(int arr[], int n) {
    int curr_sum = 0;
    int max_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
        if (curr_sum < 0) {
            curr_sum = 0;
        }
    }

    return max_sum;
}

int main() {
    int arr[MAX];
    int n;

    printf("Enter the size of the array (<= %d): ", MAX);
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Maximum sum of a subarray using brute force algorithm: %d\n", max_sum_subarray(arr, n));
    printf("Maximum sum of a subarray using greedy algorithm: %d\n", max_sum_subarray_greedy(arr, n));

    return 0;
}