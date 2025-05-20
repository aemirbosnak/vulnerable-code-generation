//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to find the maximum value in an array
int max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the maximum value in an array using Greedy Algorithm
int max_greedy(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[MAX], n;

    // Taking input from user
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Finding maximum element in array using Greedy Algorithm
    int max_greedy_val = max_greedy(arr, n);

    // Finding maximum element in array using Brute Force
    int max_brute_force_val = max(arr, n);

    // Printing the results
    printf("Maximum element in array using Greedy Algorithm: %d\n", max_greedy_val);
    printf("Maximum element in array using Brute Force: %d\n", max_brute_force_val);

    return 0;
}