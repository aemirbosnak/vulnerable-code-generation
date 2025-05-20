//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function prototypes
void inputArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void menu();

int main() {
    int arr[MAX_SIZE];
    int size;
    int choice;

    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    inputArray(arr, size);

    while (1) {
        menu();
        printf("Choose a sorting algorithm (1-4) or 5 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Using Bubble Sort:\n");
                bubbleSort(arr, size);
                printArray(arr, size);
                break;
            case 2:
                printf("Using Selection Sort:\n");
                selectionSort(arr, size);
                printArray(arr, size);
                break;
            case 3:
                printf("Using Insertion Sort:\n");
                insertionSort(arr, size);
                printArray(arr, size);
                break;
            case 4:
                printf("Using Quick Sort:\n");
                quickSort(arr, 0, size - 1);
                printArray(arr, size);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
}

void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int size) {
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void menu() {
    printf("\nSorting Algorithm Menu:\n");
    printf("1: Bubble Sort\n");
    printf("2: Selection Sort\n");
    printf("3: Insertion Sort\n");
    printf("4: Quick Sort\n");
    printf("5: Exit\n");
}