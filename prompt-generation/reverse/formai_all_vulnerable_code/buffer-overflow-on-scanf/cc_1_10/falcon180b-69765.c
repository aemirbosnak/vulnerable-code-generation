//Falcon-180B DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MIN_SIZE 10

void generate_random_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int left, int mid, int right) {
    int temp[MAX_SIZE];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort_recursive(int *arr, int size) {
    merge_sort(arr, 0, size - 1);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < MIN_SIZE) {
        printf("Invalid array size. Please enter a size greater than or equal to %d.\n", MIN_SIZE);
        return 1;
    }

    int arr[MAX_SIZE];
    generate_random_array(arr, size);

    printf("Original array:\n");
    print_array(arr, size);

    merge_sort_recursive(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}