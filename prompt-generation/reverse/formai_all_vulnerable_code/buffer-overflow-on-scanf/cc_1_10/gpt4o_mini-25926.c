//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Shocked by the chaos of the integers! Let's sort them!  
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Swapping: %d and %d!\n", *a, *b);
}

void bubbleSort(int arr[], int n) {
    printf("Starting Bubble Sort - I can't believe this mess!\n");
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                printf("Found: %d > %d, swapping!\n", arr[j], arr[j + 1]);
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        printArray(arr, n);
        if (!swapped) {
            break;
        }
    }
}

void insertionSort(int arr[], int n) {
    printf("In Shock! Now using Insertion Sort!\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            printf("Moving: %d to the right!\n", arr[j]);
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
        printf("Inserting %d at position %d!\n", key, j + 1);
        printArray(arr, n);
    }
}

void selectionSort(int arr[], int n) {
    printf("Oh No! Time to select the right numbers with Selection Sort!\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            printf("Selected %d as the minimum, swapping with %d!\n", arr[min_idx], arr[i]);
            swap(&arr[min_idx], &arr[i]);
        }
        printArray(arr, n);
    }
}

void generateRandomArray(int arr[], int n) {
    srand(time(NULL)); // Seed for randomness
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

int main() {
    int n;
    printf("How many numbers are you ready to sort? (Enter a number>0): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("That's not a valid number! Exiting in shock!\n");
        return 1;
    }

    int* arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed! Too shocked to proceed!\n");
        return 1;
    }

    generateRandomArray(arr, n);
    printf("Randomly generated array:\n");
    printArray(arr, n);

    // Commenting out sorting for space, uncomment as needed.
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    selectionSort(arr, n);

    printf("Final sorted array:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}