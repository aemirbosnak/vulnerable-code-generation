//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_VALUE 1000

void printArray(int arr[], int size) {
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("Swapped %d and %d\n", arr[j], arr[j + 1]);
                printArray(arr, size);
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            printf("Moved %d to position %d\n", arr[i], i);
            printArray(arr, size);
        }
    }
}

void insertionSort(int arr[], int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            printf("Moved %d to the right\n", arr[j + 1]);
            printArray(arr, size);
        }
        arr[j + 1] = key;
        printf("Inserted %d at position %d\n", key, j + 1);
        printArray(arr, size);
    }
}

void fillArrayRandom(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

int main() {
    int arr[MAX_NUMBERS];
    int size;

    printf("Enter the number of elements to sort (max %d): ", MAX_NUMBERS);
    scanf("%d", &size);

    if (size > MAX_NUMBERS || size <= 0) {
        printf("Invalid size! Must be between 1 and %d.\n", MAX_NUMBERS);
        return EXIT_FAILURE;
    }

    fillArrayRandom(arr, size);
    printArray(arr, size);

    printf("\n=== Bubble Sort ===\n");
    bubbleSort(arr, size);
    printArray(arr, size);

    printf("\n=== Selection Sort ===\n");
    fillArrayRandom(arr, size);  // Refresh array with random numbers
    printArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);

    printf("\n=== Insertion Sort ===\n");
    fillArrayRandom(arr, size);  // Refresh array with random numbers
    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);

    printf("Sorting completed! Thanks for watching!\n");
    return EXIT_SUCCESS;
}