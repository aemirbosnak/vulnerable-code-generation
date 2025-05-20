//Falcon-180B DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to print array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to merge two arrays
void merge(int arr1[], int arr2[], int size1, int size2) {
    int i, j, k;
    int *temp;

    // Allocate memory for temporary array
    temp = (int *)malloc(size1 + size2 * sizeof(int));

    // Merge the two arrays
    i = 0;
    j = 0;
    k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            temp[k] = arr1[i];
            i++;
        } else {
            temp[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of arr1
    while (i < size1) {
        temp[k] = arr1[i];
        i++;
        k++;
    }

    // Copy any remaining elements of arr2
    while (j < size2) {
        temp[k] = arr2[j];
        j++;
        k++;
    }

    // Copy the merged array to arr1
    for (i = 0; i < size1 + size2; i++)
        arr1[i] = temp[i];

    // Free the memory allocated for the temporary array
    free(temp);
}

// Function to merge sort an array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Unsorted array: ");
    printArray(arr, arr_size);

    // Sort the array
    mergeSort(arr, 0, arr_size - 1);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, arr_size);

    return 0;
}