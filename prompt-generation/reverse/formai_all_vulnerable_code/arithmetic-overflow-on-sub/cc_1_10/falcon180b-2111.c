//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// Function to print the array
void print_array(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Function to perform insertion sort
void insertion_sort(int arr[], int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[MAX_SIZE], size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    int index = binary_search(arr, size, target);

    if (index == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    print_array(arr, size);

    return 0;
}