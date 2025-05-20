//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the maximum value in a subarray
int findMaxSubarray(int arr[], int n, int start, int end) {
    int max = arr[start];
    for (int i = start; i <= end; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the maximum value in a subarray using greedy algorithm
int findMaxSubarrayGreedy(int arr[], int n, int start, int end) {
    int max = arr[start];
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
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
    printf("The maximum value in the array is: %d\n", findMax(arr, n));
    int start, end;
    printf("Enter the starting and ending indices of the subarray: ");
    scanf("%d %d", &start, &end);
    printf("The maximum value in the subarray is: %d\n", findMaxSubarray(arr, n, start, end));
    printf("The maximum value in the subarray using greedy algorithm is: %d\n", findMaxSubarrayGreedy(arr, n, start, end));
    return 0;
}