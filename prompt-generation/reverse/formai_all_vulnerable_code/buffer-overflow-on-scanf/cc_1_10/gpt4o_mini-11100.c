//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void merge(int* arr, int left, int mid, int right);
void mergeSort(int* arr, int left, int right);
void printArray(int* arr, int size);
int* createArray(int size);
void freeArray(int* arr);

int main() {
    int size;
    int* array;

    // Prompt user for array size
    printf("Welcome to the sophisticated sorting application!\n");
    printf("Please enter the number of elements to sort: ");
    scanf("%d", &size);

    // Create array and handle memory allocation
    array = createArray(size);
    if (array == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return EXIT_FAILURE;
    }

    // Get array elements from the user
    printf("Please enter %d integers:\n", size);
    for(int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Display original array
    printf("The original array is:\n");
    printArray(array, size);

    // Perform merge sort
    mergeSort(array, 0, size - 1);

    // Display sorted array
    printf("The sorted array is:\n");
    printArray(array, size);

    // Free allocated memory
    freeArray(array);

    printf("Sorting operation completed successfully. Have a great day!\n");
    return EXIT_SUCCESS;
}

// Merge two subarrays
void merge(int* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*) malloc(n1 * sizeof(int));
    int* R = (int*) malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(L);
    free(R);
}

// Merge sort function
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to create an array
int* createArray(int size) {
    return (int*) malloc(size * sizeof(int));
}

// Function to free an array
void freeArray(int* arr) {
    free(arr);
}