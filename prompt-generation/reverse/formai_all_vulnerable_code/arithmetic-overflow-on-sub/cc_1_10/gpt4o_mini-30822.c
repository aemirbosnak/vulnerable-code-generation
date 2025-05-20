//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Dual-pivot quicksort function
void dualPivotQuicksort(int arr[], int low, int high) {
    if (low < high) {
        if (arr[low] > arr[high]) {
            swap(&arr[low], &arr[high]);
        }

        int j = low + 1;
        int g = high - 1;
        int k = low + 1;
        int pivot1 = arr[low];
        int pivot2 = arr[high];

        while (k <= g) {
            if (arr[k] < pivot1) {
                swap(&arr[k], &arr[j]);
                j++;
            } else if (arr[k] > pivot2) {
                while (arr[g] > pivot2 && k < g) {
                    g--;
                }
                swap(&arr[k], &arr[g]);
                g--;
                if (arr[k] < pivot1) {
                    swap(&arr[k], &arr[j]);
                    j++;
                }
            }
            k++;
        }
        j--;
        g++;

        swap(&arr[low], &arr[j]);
        swap(&arr[high], &arr[g]);

        dualPivotQuicksort(arr, low, j - 1);
        dualPivotQuicksort(arr, j + 1, g - 1);
        dualPivotQuicksort(arr, g + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to get array input from user
void getInput(int **arr, int *size) {
    printf("Enter number of elements: ");
    scanf("%d", size);
    *arr = (int *)malloc(*size * sizeof(int));
    if (*arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

// Function to free allocated memory
void freeMemory(int *arr) {
    free(arr);
}

int main() {
    int *arr = NULL;
    int size = 0;

    // Input array from user
    getInput(&arr, &size);

    // Perform dual-pivot quicksort
    dualPivotQuicksort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    // Free allocated memory
    freeMemory(arr);

    return 0;
}