//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to calculate the maximum value of a given array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to calculate the maximum value of a given array using greedy algorithm
int getMaxGreedy(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate the minimum value of a given array using greedy algorithm
int getMinGreedy(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main() {
    int arr[MAX_SIZE];
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array: ");
    printArray(arr, n);

    // Calculate the maximum value of the array using greedy algorithm
    int max = getMaxGreedy(arr, n);
    printf("Maximum value of the array: %d\n", max);

    // Calculate the minimum value of the array using greedy algorithm
    int min = getMinGreedy(arr, n);
    printf("Minimum value of the array: %d\n", min);

    return 0;
}