//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 10
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int size;
} array;

void print_array(array arr) {
    for (int i = 0; i < arr.size; ++i) {
        printf("%d ", arr.arr[i]);
    }
    printf("\b\n");
}

int csearch(array *arr, int value) {
    if (arr->size == 0) {
        printf("Array is empty.\n");
        return -1;
    }

    int pivot = arr->arr[arr->size / 2];
    int left = 0;
    int right = arr->size - 1;

    while (left <= right) {
        if (arr->arr[left] == value) {
            return left;
        }

        if (arr->arr[left] < pivot) {
            int temp = arr->arr[left];
            arr->arr[left] = arr->arr[right];
            arr->arr[right] = temp;
            right--;
        } else {
            left++;
        }
    }

    return -1;
}

int main() {
    array arr = {0};
    int n, value;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < MIN_SIZE || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    arr.size = n;

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr.arr[i]);
    }

    print_array(arr);
    printf("Enter the value to search for: ");
    scanf("%d", &value);

    int index = csearch(&arr, value);

    if (index == -1) {
        printf("Value not found.\n");
    } else {
        printf("Value found at index %d.\n", index);
    }

    return 0;
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}