//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void display(int arr[], int n) {
    printf("Current array: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIdx;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
}

int main() {
    int arr[MAX_ELEMENTS], n;

    printf("Welcome to the Mind-Bending Sorting Program!\n");
    printf("How many elements do you want to sort? (max %d): ", MAX_ELEMENTS);
    scanf("%d", &n);

    if(n > MAX_ELEMENTS || n <= 0) {
        printf("Invalid number of elements! Please try again.\n");
        return 1;
    }

    generateRandomArray(arr, n);
    display(arr, n);

    printf("Starting with Bubble Sort...\n");
    bubbleSort(arr, n);
    display(arr, n);

    printf("Refreshing the array with new random elements...\n");
    generateRandomArray(arr, n);
    display(arr, n);

    printf("Now, let’s try Insertion Sort...\n");
    insertionSort(arr, n);
    display(arr, n);

    printf("Let's refresh again for one last sorting...\n");
    generateRandomArray(arr, n);
    display(arr, n);

    printf("Final trial: Selection Sort...\n");
    selectionSort(arr, n);
    display(arr, n);

    printf("All sortings completed! Behold the final sorted array:\n");
    display(arr, n);

    printf("Thank you for experiencing the mind-bending journey of sorting!\n");
    return 0;
}