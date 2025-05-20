//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void merge(int array[], int left[], int left_size, int right[], int right_size);
void merge_sort(int array[], int size);

int main() {
    int array[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    merge_sort(array, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void merge(int array[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    while (i < left_size) {
        array[k++] = left[i++];
    }

    while (j < right_size) {
        array[k++] = right[j++];
    }
}

void merge_sort(int array[], int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;
    int left[mid], right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(array, left, mid, right, size - mid);
}