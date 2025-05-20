//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Bubble Shift Sort function
void bubbleShiftSort(int arr[], int n) {
    int i, j, flag = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
                // Shift all elements greater than swapped element to the right
                for (int k = j + 1; k < n - i; k++) {
                    if (arr[k] <= arr[k - 1]) {
                        swap(&arr[k], &arr[k - 1]);
                    }
                }
            }
        }
        // If no swaps were made in inner loop, then the array is already sorted
        if (flag == 0) {
            break;
        }
        flag = 0;
    }
}

// Function to print array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleShiftSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}