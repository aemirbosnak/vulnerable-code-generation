//FormAI DATASET v1.0 Category: Sorting ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int i, n, *arr;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // dynamically allocate memory for array
    arr = (int*)malloc(sizeof(int)*n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // call selection sort
    selection_sort(arr, n);

    printf("After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // free dynamically allocated memory
    free(arr);

    return 0;
}