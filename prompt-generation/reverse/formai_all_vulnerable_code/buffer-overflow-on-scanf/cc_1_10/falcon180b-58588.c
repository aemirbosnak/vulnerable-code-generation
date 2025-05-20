//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value of a subarray ending at index i
int max_ending_here(int arr[], int i, int n) {
    int max = arr[i];
    for (int j = i + 1; j < n; j++) {
        if (arr[j] > max) {
            max = arr[j];
        }
    }
    return max;
}

// Function to find the maximum value of a subarray starting at index i
int max_starting_here(int arr[], int i, int n) {
    int max = arr[i];
    for (int j = i; j < n; j++) {
        if (arr[j] > max) {
            max = arr[j];
        }
    }
    return max;
}

// Function to implement the greedy algorithm for the maximum subarray problem
int max_subarray(int arr[], int n) {
    int max_so_far = arr[0];
    int max_ending_here = arr[0];
    for (int i = 1; i < n; i++) {
        max_ending_here = max_ending_here > 0? max_ending_here + arr[i] : arr[i];
        max_so_far = max_ending_here > max_so_far? max_ending_here : max_so_far;
    }
    return max_so_far;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = max_subarray(arr, n);
    printf("The maximum subarray sum is: %d\n", max);

    return 0;
}