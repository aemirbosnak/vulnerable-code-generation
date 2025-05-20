//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
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

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Allocate memory dynamically for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum and minimum values in the array
    int max = findMax(arr, n);
    int min = findMin(arr, n);

    // Print the results
    printf("The maximum value in the array is %d\n", max);
    printf("The minimum value in the array is %d\n", min);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}