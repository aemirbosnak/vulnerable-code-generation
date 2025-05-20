//FormAI DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// The puzzle here is to sort an array of integers, but with a catch
// You cannot use any of the traditional sorting algorithms (e.g. bubble sort, quicksort, etc)
// Additionally, you must use at least 2 different algorithms to sort the array
// Good luck!

// Algorithm 1: Insertion sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Algorithm 2: Selection sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Combine two sorted arrays into one sorted array
void merge(int arr1[], int n1, int arr2[], int n2, int sorted[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            sorted[k++] = arr1[i++];
        } else {
            sorted[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        sorted[k++] = arr1[i++];
    }
    while (j < n2) {
        sorted[k++] = arr2[j++];
    }
}

int main() {
    int arr[] = {3, 6, 2, 8, 1, 4, 7, 5}; // Unsorted array

    // First, we will use insertion sort to sort the odd-indexed elements
    for (int i = 1; i < 8; i += 2) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 2] = arr[j];
            j -= 2;
        }
        arr[j + 2] = key;
    }

    // Next, we will use selection sort to sort the even-indexed elements
    for (int i = 0; i < 8; i += 2) {
        int min_idx = i;
        for (int j = i + 2; j < 8; j += 2) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    // Finally, we will merge the two sorted subsequences into one sorted array
    int sorted[8];
    merge(arr, 4, arr + 4, 4, sorted);
    for (int i = 0; i < 8; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    return 0;
}