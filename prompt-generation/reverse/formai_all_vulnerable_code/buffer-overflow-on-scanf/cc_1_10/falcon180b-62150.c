//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

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

// Function to perform a greedy algorithm to find the maximum sum of non-overlapping subarrays
int greedyAlgorithm(int arr[], int size) {
    int max = arr[0];
    int sum = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            sum += max;
        } else {
            sum -= arr[i-1];
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Prompt user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the greedy algorithm function to find the maximum sum of non-overlapping subarrays
    int maxSum = greedyAlgorithm(arr, size);

    // Print the maximum sum
    printf("The maximum sum of non-overlapping subarrays is: %d\n", maxSum);

    return 0;
}