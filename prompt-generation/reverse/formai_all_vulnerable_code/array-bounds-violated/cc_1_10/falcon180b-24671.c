//Falcon-180B DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>

// function to print the elements of an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// function to merge two sorted arrays
void merge(int arr1[], int size1, int arr2[], int size2) {
    int i, j, k;
    int temp[100]; // temporary array to hold the merged array
    int size = size1 + size2;

    // copy the elements of arr1 and arr2 into temp
    for (i = 0; i < size1; i++)
        temp[i] = arr1[i];
    for (j = 0; j < size2; j++)
        temp[size1 + j] = arr2[j];

    // merge the two arrays
    i = 0;
    j = size1;
    k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j])
            arr1[k++] = arr1[i++];
        else
            arr1[k++] = arr2[j++];
    }

    // copy any remaining elements of arr1
    while (i < size1)
        arr1[k++] = arr1[i++];

    // copy any remaining elements of arr2
    while (j < size2)
        arr1[k++] = arr2[j++];
}

// function to perform merge sort
void mergeSort(int arr[], int size) {
    if (size <= 1)
        return;

    // divide the array into two halves
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // copy the elements of the original array into the left and right arrays
    int i;
    for (i = 0; i < mid; i++)
        left[i] = arr[i];
    for (i = mid; i < size; i++)
        right[i - mid] = arr[i];

    // recursively sort the left and right arrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // merge the sorted left and right arrays
    merge(left, mid, right, size - mid);

    // copy the sorted array back into the original array
    for (i = 0; i < size; i++)
        arr[i] = left[i];
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    mergeSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}