//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
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

// Function to find the maximum difference between two elements in an array
int findMaxDiff(int arr[], int n) {
    int maxDiff = 0;
    for (int i = 0; i < n - 1; i++) {
        int minVal = findMin(arr, n - i);
        int maxVal = findMax(arr, n - i);
        int diff = maxVal - minVal;
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }
    return maxDiff;
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

    int maxDiff = findMaxDiff(arr, n);
    printf("The maximum difference between two elements in the array is: %d\n", maxDiff);

    return 0;
}