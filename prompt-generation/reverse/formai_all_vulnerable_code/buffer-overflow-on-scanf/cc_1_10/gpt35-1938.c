//FormAI DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocating memory for the array
    int *arr = malloc(size * sizeof(int));

    printf("Enter the elements of the array:\n");
    for(i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, size-1);

    printf("Sorted array: ");
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // free memory 

    return 0;
}

// Merge function to merge two sorted arrays into one sorted array
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int subArr1Size = mid - left + 1;
    int subArr2Size = right - mid;
    int *subArr1 = malloc(subArr1Size * sizeof(int));
    int *subArr2 = malloc(subArr2Size * sizeof(int));

    // Copy elements from arr to subArr1
    for(i=0; i<subArr1Size; i++) {
        subArr1[i] = arr[left + i];
    }

    // Copy elements from arr to subArr2
    for(j=0; j<subArr2Size; j++) {
        subArr2[j] = arr[mid + 1 + j];
    }

    i = 0; // initial index of subArr1
    j = 0; // initial index of subArr2
    k = left; // initial index of merged array

    while(i < subArr1Size && j < subArr2Size) {
        if(subArr1[i] <= subArr2[j]) {
            arr[k] = subArr1[i];
            i++;
        } else {
            arr[k] = subArr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of subArr1, if any
    while(i < subArr1Size) {
        arr[k] = subArr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of subArr2, if any
    while(j < subArr2Size) {
        arr[k] = subArr2[j];
        j++;
        k++;
    }

    free(subArr1); // free memory 
    free(subArr2); // free memory 
}

// Merge sort function
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid); // sort left sub-array recursively
        mergeSort(arr, mid+1, right); // sort right sub-array recursively

        merge(arr, left, mid, right); // merge the two sorted sub-arrays
    }
}