//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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

// Function to perform greedy algorithm
int greedy(int arr[], int n) {
    int max = findMax(arr, n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == max) {
            sum += arr[i];
        }
    }
    return sum;
}

// Function to generate random array
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    generateArray(arr, n);
    printf("Original array:\n");
    printArray(arr, n);
    int sum = greedy(arr, n);
    printf("Sum of maximum elements: %d\n", sum);
    return 0;
}