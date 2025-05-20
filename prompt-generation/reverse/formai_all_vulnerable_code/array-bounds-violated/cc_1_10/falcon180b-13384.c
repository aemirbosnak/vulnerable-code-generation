//Falcon-180B DATASET v1.0 Category: Recursive ; Style: distributed
#include<stdio.h>

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to merge two arrays
void merge(int arr1[], int arr2[], int size1, int size2) {
    int i = 0, j = 0, k = 0;
    int temp[size1 + size2];

    // Copy the elements of arr1
    for (i = 0; i < size1; i++) {
        temp[k++] = arr1[i];
    }

    // Copy the elements of arr2
    for (j = 0; j < size2; j++) {
        temp[k++] = arr2[j];
    }

    // Merge the arrays
    for (i = 0; i < size1; i++) {
        arr1[i] = temp[i];
    }
    for (j = 0; j < size2; j++) {
        arr2[j] = temp[size1 + j];
    }
}

// Recursive function to merge sort
void mergeSort(int arr[], int size) {
    if (size == 1) {
        return;
    }
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Copy the elements of left and right arrays
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int j = mid; j < size; j++) {
        right[j - mid] = arr[j];
    }

    // Recursively sort the left and right arrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted arrays
    merge(left, right, mid, size - mid);

    // Copy the sorted array to the original array
    for (int i = 0; i < size; i++) {
        arr[i] = right[i];
    }
}

// Main function
int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Unsorted array: ");
    printArray(arr, size);

    // Sort the array
    mergeSort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}