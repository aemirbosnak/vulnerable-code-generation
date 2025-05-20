//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
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

void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }
}

void sortAndPrint(char *sortType, int arr[], int n) {
    printf("Original Array: \n");
    printArray(arr, n);
    
    if (strcmp(sortType, "bubble") == 0) {
        bubbleSort(arr, n);
        printf("Sorted Array using Bubble Sort: \n");
    } else if (strcmp(sortType, "selection") == 0) {
        selectionSort(arr, n);
        printf("Sorted Array using Selection Sort: \n");
    } else if (strcmp(sortType, "insertion") == 0) {
        insertionSort(arr, n);
        printf("Sorted Array using Insertion Sort: \n");
    } else {
        printf("Unknown sort type!\n");
        return;
    }

    printArray(arr, n);
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return -1;
    }

    generateRandomArray(arr, n);

    char sortType[10];
    printf("Select sort type (bubble/selection/insertion): ");
    scanf("%s", sortType);

    sortAndPrint(sortType, arr, n);

    return 0;
}