//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void merge(int arr[], int left, int mid, int right, int ascending);
void mergeSort(int arr[], int left, int right, int ascending);
int partition(int arr[], int low, int high, int ascending);
void quickSort(int arr[], int low, int high, int ascending);
void printArray(int arr[], int size);
void swap(int *a, int *b);

// Main function
int main() {
    int n, choice, order;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return -1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Choose sorting algorithm:\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Choose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice: ");
    scanf("%d", &order);

    int ascending = (order == 1) ? 1 : 0;

    switch (choice) {
        case 1:
            mergeSort(array, 0, n - 1, ascending);
            break;

        case 2:
            quickSort(array, 0, n - 1, ascending);
            break;

        default:
            printf("Invalid choice!\n");
            free(array);
            return 0;
    }

    printf("Sorted array:\n");
    printArray(array, n);

    free(array);
    return 0;
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right, int ascending) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Merge Sort function
void mergeSort(int arr[], int left, int right, int ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high, int ascending) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if ((ascending && arr[j] <= pivot) || (!ascending && arr[j] >= pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high, int ascending) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);
        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

// Swap function for swapping two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}