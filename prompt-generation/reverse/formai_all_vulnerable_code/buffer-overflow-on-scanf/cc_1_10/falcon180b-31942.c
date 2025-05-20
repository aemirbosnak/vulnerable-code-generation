//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to find the maximum value of an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the maximum value of an array using greedy algorithm
int findMaxGreedy(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the maximum value of an array using dynamic programming
int findMaxDynamic(int arr[], int size) {
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

    // Prompt user to enter size of array
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Prompt user to enter elements of array
    printf("Enter elements of array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Find maximum value of array using brute force method
    int max1 = findMax(arr, size);
    printf("Maximum value of array using brute force method: %d\n", max1);

    // Find maximum value of array using greedy algorithm
    int max2 = findMaxGreedy(arr, size);
    printf("Maximum value of array using greedy algorithm: %d\n", max2);

    // Find maximum value of array using dynamic programming
    int max3 = findMaxDynamic(arr, size);
    printf("Maximum value of array using dynamic programming: %d\n", max3);

    return 0;
}