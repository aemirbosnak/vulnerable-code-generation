//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);
char menu();

int main() {
    int *arr;
    int n, choice;

    // Greeting and input
    printf("Welcome to the Sorting Showcase!\n");
    printf("How many elements do you want to sort? ");
    scanf("%d", &n);
    
    // Dynamic memory allocation for array
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Menu for sorting choice
    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Sorting using Bubble Sort...\n");
                bubbleSort(arr, n);
                break;
            case 2:
                printf("Sorting using Selection Sort...\n");
                selectionSort(arr, n);
                break;
            case 3:
                printf("Sorting using Quick Sort...\n");
                quickSort(arr, 0, n - 1);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                free(arr);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printArray(arr, n);
    }
}

// Function implementations
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted using Bubble Sort!\n");
}

void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        // Swap
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
    printf("Array sorted using Selection Sort!\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap pivot
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    printf("Array sorted using Quick Sort!\n");
}

void printArray(int arr[], int size) {
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

char menu() {
    char choice;
    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Quick Sort\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    return choice;
}