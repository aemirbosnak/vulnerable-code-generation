//Falcon-180B DATASET v1.0 Category: Recursive ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to perform quick sort on an array
void quickSort(int arr[], int low, int high) {
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    // Partition
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // Recursion
    if (low < j)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform quick sort
    quickSort(arr, 0, n - 1);

    // Print sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}