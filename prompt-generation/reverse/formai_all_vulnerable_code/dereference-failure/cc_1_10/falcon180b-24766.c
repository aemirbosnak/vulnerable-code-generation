//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find the maximum sum of a subarray ending at index i
int max_sum(int arr[], int i, int n) {
    int sum = 0;
    int max_sum = 0;
    for (int j = i; j < n; j++) {
        sum += arr[j];
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}

// Function to find the maximum sum of a subarray starting at index i
int max_sum_starting_at(int arr[], int i, int n) {
    int sum = 0;
    int max_sum = 0;
    for (int j = i; j < n; j++) {
        sum += arr[j];
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}

// Function to find the maximum sum of a subarray using the greedy algorithm
int max_sum_greedy(int arr[], int n) {
    int max_sum = arr[0];
    int current_sum = arr[0];
    for (int i = 1; i < n; i++) {
        if (current_sum > 0) {
            current_sum += arr[i];
        } else {
            current_sum = arr[i];
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
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

    // Find the maximum sum of a subarray ending at index i
    int max_end = max_sum(arr, 0, n);
    printf("The maximum sum of a subarray ending at index 0 is %d\n", max_end);

    // Find the maximum sum of a subarray starting at index i
    int max_start = max_sum_starting_at(arr, 0, n);
    printf("The maximum sum of a subarray starting at index 0 is %d\n", max_start);

    // Find the maximum sum of a subarray using the greedy algorithm
    int max_greedy = max_sum_greedy(arr, n);
    printf("The maximum sum of a subarray using the greedy algorithm is %d\n", max_greedy);

    return 0;
}