//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
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

// Function to implement the greedy algorithm
void greedyAlgorithm(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    printf("The maximum sum that can be obtained is %d\n", sum);
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
    printf("The maximum value in the array is %d\n", max);
    printf("The minimum value in the array is %d\n", min);
    greedyAlgorithm(arr, n);
    return 0;
}