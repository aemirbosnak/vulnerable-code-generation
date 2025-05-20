//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function to sort an array in ascending order
void sort(int *arr, int n) {
    // Base case: array is empty or has only one element
    if (n <= 1)
        return;

    // Recursive case: split the array into two halves and sort each half
    int mid = n / 2;
    int *left = malloc(mid * sizeof(int));
    int *right = malloc((n - mid) * sizeof(int));
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];
    sort(left, mid);
    sort(right, n - mid);

    // Merge the two sorted halves into the original array
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < mid)
        arr[k++] = left[i++];
    while (j < n - mid)
        arr[k++] = right[j++];

    // Free the memory allocated for the two halves
    free(left);
    free(right);
}

int main() {
    // Get the size of the array from the user
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = malloc(n * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort the array
    sort(arr, n);

    // Print the sorted array
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Free the memory allocated for the array
    free(arr);

    return 0;
}