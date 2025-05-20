//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void merge(int arr[], int left, int mid, int right, int ascending);
void mergeSort(int arr[], int left, int right, int ascending);
void printArray(int arr[], int size);
void fillArray(int arr[], int size);
int getArraySize();

int main() {
    int size;
    int *arr;
    int choice;

    printf("Welcome to the Sophisticated Merge Sort Program!\n");
    size = getArraySize();
    
    // Memory allocation for the array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    fillArray(arr, size);
    
    printf("Original array:\n");
    printArray(arr, size);
    
    printf("Choose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice (1 or 2): ");
    
    scanf("%d", &choice);
    
    if (choice == 1) {
        mergeSort(arr, 0, size - 1, 1);
        printf("Sorted array in ascending order:\n");
    } else if (choice == 2) {
        mergeSort(arr, 0, size - 1, 0);
        printf("Sorted array in descending order:\n");
    } else {
        printf("Invalid choice! Exiting program.\n");
        free(arr);
        return 1;
    }

    printArray(arr, size);

    // Free the allocated memory
    free(arr);
    return 0;
}

void mergeSort(int arr[], int left, int right, int ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }
}

void merge(int arr[], int left, int mid, int right, int ascending) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = left; // Initial index of merged sub-array
    while (i < n1 && j < n2) {
        if ((ascending && L[i] <= R[j]) || (!ascending && L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    free(L);
    free(R);
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

int getArraySize() {
    int size;
    printf("Enter size of the array (greater than 0): ");
    scanf("%d", &size);
    while (size <= 0) {
        printf("Please enter a valid size: ");
        scanf("%d", &size);
    }
    return size;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}