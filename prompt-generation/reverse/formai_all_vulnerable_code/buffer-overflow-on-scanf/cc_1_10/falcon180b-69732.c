//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} element;

void create_array(element arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }
}

void print_array(element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

void swap(element* a, element* b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(element arr[], int size) {
    int min_idx;
    for (int i = 0; i < size - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].data < arr[min_idx].data) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

int binary_search(element arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].data == target) {
            return mid;
        } else if (arr[mid].data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    srand(time(NULL));

    element arr[MAX_SIZE];
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    create_array(arr, size);
    print_array(arr, size);

    printf("Enter the target value to search: ");
    scanf("%d", &target);

    int result = binary_search(arr, size, target);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}