//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to merge two sorted arrays
void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to sort an array using merge sort
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = (left + right) / 2;

        // Sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    // Get the size of the array
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);

    // Get the elements of the array
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    // Print the unsorted array
    printf("Unsorted array: ");
    printArray(arr, size);

    // Sort the array using merge sort
    mergeSort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}