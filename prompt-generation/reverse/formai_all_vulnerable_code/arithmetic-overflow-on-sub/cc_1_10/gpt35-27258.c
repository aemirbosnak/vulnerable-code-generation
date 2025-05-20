//FormAI DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000 // Maximum size of array to be sorted

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    for(i = 0; i < n-1; i++) {
        minIndex = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Function to print the given array
void printArray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n, i, choice;

    // Seed for random number generation
    srand(time(0));

    printf("Enter the size of array (less than or equal to %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Generate random numbers and store in array
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    do {
        // Menu for sorting options
        printf("Enter your choice:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Array before sorting:\n");
                printArray(arr, n);
                bubbleSort(arr, n);
                printf("Array after bubble sort:\n");
                printArray(arr, n);
                break;
            case 2:
                printf("Array before sorting:\n");
                printArray(arr, n);
                selectionSort(arr, n);
                printf("Array after selection sort:\n");
                printArray(arr, n);
                break;
            case 3:
                printf("Array before sorting:\n");
                printArray(arr, n);
                insertionSort(arr, n);
                printf("Array after insertion sort:\n");
                printArray(arr, n);
                break;
            case 4:
                printf("Exiting..\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while(choice != 4);

    return 0;
}