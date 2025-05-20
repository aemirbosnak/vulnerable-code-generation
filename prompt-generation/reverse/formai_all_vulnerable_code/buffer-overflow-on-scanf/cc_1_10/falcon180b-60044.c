//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>

#define MAX_SIZE 100

// Function to find the maximum value
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to apply greedy algorithm to find maximum sum
int greedyAlgorithm(int arr[], int size) {
    int max = findMax(arr, size);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == max) {
            sum += arr[i];
            arr[i] = -1;
        }
    }
    return sum;
}

int main() {
    int arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int maxSum = greedyAlgorithm(arr, size);
    printf("The maximum sum using greedy algorithm is: %d\n", maxSum);
    printf("The array after applying greedy algorithm is:\n");
    printArray(arr, size);
    return 0;
}