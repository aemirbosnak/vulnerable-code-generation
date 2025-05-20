//Falcon-180B DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to generate a random permutation of integers from 0 to n-1
void generatePermutation(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to find the kth smallest element in an array
int kthSmallest(int arr[], int n, int k) {
    if (n == 1) {
        return arr[0];
    }
    int pivot = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < pivot) {
            pivot = arr[i];
        }
    }
    if (k == 1) {
        return pivot;
    }
    if (k < n - 1) {
        int newArr[n - 1];
        for (int i = 0; i < n - 1; i++) {
            if (i < k - 1 || arr[i] > pivot) {
                newArr[i] = arr[i];
            } else if (i == k - 1) {
                newArr[i] = pivot;
            }
        }
        return kthSmallest(newArr, n - 1, k);
    } else {
        int newArr[n - 1];
        for (int i = 0; i < n - 1; i++) {
            if (i < k - 1 || arr[i] > pivot) {
                newArr[i] = arr[i];
            } else if (i == k - 1) {
                newArr[i] = arr[n - 1];
            }
        }
        return kthSmallest(newArr, n - 1, k);
    }
}

int main() {
    int n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[MAX];
    generatePermutation(arr, n);
    printf("Original array: ");
    printArray(arr, n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    int result = kthSmallest(arr, n, k);
    printf("The %dth smallest element is: %d\n", k, result);
    return 0;
}