//FormAI DATASET v1.0 Category: Sorting ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Function prototypes
bool is_sorted(int*, int);
void paranoid_sort(int*, int);
void swap(int*, int*);

int main() {
    int arr[MAX_SIZE], size;
    printf("Enter the size of the array (Max size: %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size > MAX_SIZE) {
        printf("Size exceeds max limit. Sorry, can't help in this case.");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    paranoid_sort(arr, size);
    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

/* 
 * Function to check if an array is sorted in ascending order
 */
bool is_sorted(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

/* 
 * A paranoid version of bubble sort
 */
void paranoid_sort(int* arr, int size) {
    int passes = size - 1;
    while (passes > 0) {
        for (int i = 0; i < passes; i++) {
            if (is_sorted(arr, size)) {
                printf("Array is already sorted. No more sorting required.\n");
                return;
            }
            if (arr[i] > arr[i + 1]) {
                printf("Swapping values at index %d and %d\n", i, i + 1);
                swap(&arr[i], &arr[i + 1]);
            }
        }
        passes--;
    }
}

/*
 * A function to swap two integers using pointers
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}