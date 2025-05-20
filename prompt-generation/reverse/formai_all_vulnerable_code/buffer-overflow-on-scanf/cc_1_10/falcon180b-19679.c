//Falcon-180B DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Recursive function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    int mid;

    // Base case
    if (left >= right)
        return;

    // Find the middle point
    mid = left + (right - left) / 2;

    // Sort the first half
    mergeSort(arr, left, mid);

    // Sort the second half
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i - left];
}

// Main function
int main() {
    int n;

    // Prompt user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array:\n");
    printArray(arr, n);

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}