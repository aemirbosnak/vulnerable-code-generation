//Falcon-180B DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate random permutation
void permute(int arr[], int left, int right) {
    // Base case
    if (left == right) {
        return;
    }

    // Randomly choose a pivot
    int pivot = rand() % (right - left + 1) + left;

    // Partition the array
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    // Recursively permute the two partitions
    permute(arr, left, j);
    permute(arr, i, right);
}

// Function to generate random permutation
void generatePermutation(int arr[], int n) {
    srand(time(NULL));
    permute(arr, 0, n - 1);
}

// Function to find the kth smallest element
int kthSmallest(int arr[], int n, int k) {
    // Generate a random permutation of the array
    generatePermutation(arr, n);

    // Return the kth smallest element
    return arr[k - 1];
}

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    int result = kthSmallest(arr, n, k);
    printf("The %dth smallest element is: %d\n", k, result);
    return 0;
}