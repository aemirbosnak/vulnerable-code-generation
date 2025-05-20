//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);
void runSorting(int choice, int type, int arr[], int n);

// Enum for sorting type selection
typedef enum {
    INT,
    FLOAT
} DataType;

// Enum for sorting algorithm selection
typedef enum {
    BUBBLE = 1,
    SELECTION,
    INSERTION
} SortingAlgorithm;

// Main function 
int main() {
    int n, choice, type;

    printf("Configurable Sorting Program\n");
    printf("-------------------------------\n");
    
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    
    printf("Choose data type:\n1. Integer\n2. Float\nYour choice: ");
    scanf("%d", &type);
    
    if (type == 1) {
        int *arr = (int *)malloc(n * sizeof(int));

        printf("Enter %d integers:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nYour choice: ");
        scanf("%d", &choice);
        runSorting(choice, INT, (int *)arr, n);
        
        free(arr);
    } else if (type == 2) {
        float *arr = (float *)malloc(n * sizeof(float));

        printf("Enter %d floating-point numbers:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%f", &arr[i]);
        }

        printf("Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nYour choice: ");
        scanf("%d", &choice);
        runSorting(choice, FLOAT, (int *)arr, n);
        
        free(arr);
    } else {
        printf("Invalid choice. Exiting program.\n");
    }

    return 0;
}

// Sorting functions implementations
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Wrapper function to run the selected sorting
void runSorting(int choice, int type, int arr[], int n) {
    switch (choice) {
        case BUBBLE:
            bubbleSort(arr, n);
            printArray(arr, n);
            break;
        case SELECTION:
            selectionSort(arr, n);
            printArray(arr, n);
            break;
        case INSERTION:
            insertionSort(arr, n);
            printArray(arr, n);
            break;
        default:
            printf("Invalid sorting algorithm choice.\n");
            break;
    }
}