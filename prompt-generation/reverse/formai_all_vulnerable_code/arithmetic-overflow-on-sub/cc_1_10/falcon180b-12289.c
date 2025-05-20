//Falcon-180B DATASET v1.0 Category: Sorting ; Style: visionary
// This is a visionary C program that sorts an array of integers using the merge sort algorithm.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to merge two sorted arrays into one
void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            arr[k++] = arr[i++];
        } else {
            arr[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        arr[k++] = arr[i++];
    }
}

// Function to perform merge sort recursively
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
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

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}