//FormAI DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int size) {
    int i, j, temp;
    for (i = 1; i < size; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge(int arr[], int left[], int right[], int size_left, int size_right) {
    int i, j, k;
    i = j = k = 0;
    while (i < size_left && j < size_right) {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < size_left)
        arr[k++] = left[i++];
    while (j < size_right)
        arr[k++] = right[j++];
}

void merge_sort(int arr[], int size) {
    if (size < 2)
        return;
    int mid = size / 2;
    int left[mid], right[size-mid];
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int j = mid; j < size; j++)
        right[j-mid] = arr[j];
    merge_sort(left, mid);
    merge_sort(right, size-mid);
    merge(arr, left, right, mid, size-mid);
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    printf("Original array: ");
    print_array(arr, n);
    printf("Insertion sort: ");
    insertion_sort(arr, n);
    print_array(arr, n);
    printf("Merge sort: ");
    merge_sort(arr, n);
    print_array(arr, n);
    return 0;
}