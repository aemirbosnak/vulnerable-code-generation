//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

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

// Function to find the minimum value in an array
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum difference between two numbers in an array
int maxDiff(int arr[], int n) {
    int max_diff = 0;
    int min_val = findMin(arr, n);
    for (int i = 0; i < n; i++) {
        if (arr[i] - min_val > max_diff) {
            max_diff = arr[i] - min_val;
        }
    }
    return max_diff;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, n);
    int min = findMin(arr, n);
    int max_diff = maxDiff(arr, n);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Maximum difference: %d\n", max_diff);

    return 0;
}