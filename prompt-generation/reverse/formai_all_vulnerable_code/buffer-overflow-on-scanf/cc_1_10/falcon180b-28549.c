//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Function to implement the Greedy Algorithm
int greedyAlgorithm(int arr[], int n) {
    int max = findMax(arr, n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == max) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n;

    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the Greedy Algorithm function and print the result
    int sum = greedyAlgorithm(arr, n);
    printf("The sum of the elements in the array is: %d\n", sum);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}