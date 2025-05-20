//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void quickSort(int *array, int low, int high);
int partition(int *array, int low, int high);
void printArray(int *array, int size);
void generateRandomArray(int *array, int size);
double measureSortingTime(int *array, int size);

int main() {
    int size = 0;
    printf("Welcome to the Brave Quick Sort Program!\n");
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("You must enter a positive integer!\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generate a random array and print it
    generateRandomArray(array, size);
    printf("Unsorted array:\n");
    printArray(array, size);
    
    // Measure and perform the sorting
    double sortingTime = measureSortingTime(array, size);

    printf("Sorted array:\n");
    printArray(array, size);
    
    printf("Time taken to sort: %.6f seconds\n", sortingTime);
    
    // Free the allocated memory
    free(array);
    return 0;
}

// Function to perform Quick Sort
void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Function to partition the array
int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

// Function to print the array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to generate a random array
void generateRandomArray(int *array, int size) {
    srand(time(0));  // Seed for random number generation
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;  // Random numbers up to 1000
    }
}

// Function to measure sorting time
double measureSortingTime(int *array, int size) {
    clock_t start, end;
    start = clock();
    quickSort(array, 0, size - 1);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;  // Return time in seconds
}