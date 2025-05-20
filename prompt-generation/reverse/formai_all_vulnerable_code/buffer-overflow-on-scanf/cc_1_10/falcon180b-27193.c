//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to find the optimal solution using the Greedy Algorithm
void greedyAlgorithm(int arr[], int n) {
    int i, j, max, temp;
    int res[MAX_SIZE];
    int count = 0;

    // Initialize the result array
    for (i = 0; i < n; i++) {
        res[i] = 0;
    }

    // Sort the array in non-increasing order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Find the optimal solution
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (max + arr[i] > arr[i]) {
            max += arr[i];
            res[count++] = arr[i];
        }
    }

    // Print the result
    printf("Optimal solution: ");
    for (i = 0; i < count; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[MAX_SIZE], n;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Run the Greedy Algorithm
    greedyAlgorithm(arr, n);

    return 0;
}