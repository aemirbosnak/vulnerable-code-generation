//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to find the optimal solution using Greedy Algorithm
void optimalSolution(int arr[], int n) {
    int i, j, k;
    int maxIndex = 0;
    int maxValue = arr[0];

    // Find the maximum element in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }

    // Sort the array in descending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Find the maximum element in the sorted array
    for (i = 0; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = 0;
        }
    }

    // Print the optimal solution
    printf("The optimal solution is: %d\n", maxValue);
}

int main() {
    int arr[MAX], n;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the optimal solution using Greedy Algorithm
    optimalSolution(arr, n);

    return 0;
}