//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;
    
    printf("Welcome to the Quick Sort Program!\n");
    printf("Please enter the number of elements you want to sort: ");
    scanf("%d", &size);

    if(size <= 0) {
        printf("Invalid size. Exiting...\n");
        return 1;
    }

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Seed for randomness
    srand(time(0));

    // Fill the array with random numbers from 1 to 100
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1; 
    }

    printf("Unsorted array:\n");
    printArray(array, size);

    quickSort(array, 0, size - 1);

    printf("Sorted array:\n");
    printArray(array, size);

    // Free the allocated memory
    free(array);

    return 0;
}