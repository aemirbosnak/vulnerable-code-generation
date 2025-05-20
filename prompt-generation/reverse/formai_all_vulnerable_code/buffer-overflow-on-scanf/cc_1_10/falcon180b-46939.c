//Falcon-180B DATASET v1.0 Category: Recursive ; Style: interoperable
#include <stdio.h>

#define MAX 100

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Recursive function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        int i = left, j = mid + 1, k = 0;
        int temp[MAX];

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

        // Copy the temp array to arr, so that arr now
        // contains sorted elements
        for (i = left; i <= right; i++)
            arr[i] = temp[i];
    }
}

// Main function
int main() {
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort the array using Merge Sort
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}