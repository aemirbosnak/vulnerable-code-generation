//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>

#define MAX_SIZE 100

// Function to find the maximum value in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the maximum value in an array using divide and conquer approach
int findMaxDivideAndConquer(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int leftMax = findMaxDivideAndConquer(arr, low, mid);
    int rightMax = findMaxDivideAndConquer(arr, mid + 1, high);
    if (leftMax > rightMax) {
        return leftMax;
    } else {
        return rightMax;
    }
}

// Function to find the maximum value in an array using dynamic programming approach
int findMaxDynamicProgramming(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum value in the array using brute force approach
    int maxBruteForce = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxBruteForce) {
            maxBruteForce = arr[i];
        }
    }
    printf("The maximum value in the array is: %d\n", maxBruteForce);

    // Find the maximum value in the array using divide and conquer approach
    int maxDivideAndConquer = findMaxDivideAndConquer(arr, 0, size - 1);
    printf("The maximum value in the array using divide and conquer approach is: %d\n", maxDivideAndConquer);

    // Find the maximum value in the array using dynamic programming approach
    int maxDynamicProgramming = findMaxDynamicProgramming(arr, size);
    printf("The maximum value in the array using dynamic programming approach is: %d\n", maxDynamicProgramming);

    return 0;
}