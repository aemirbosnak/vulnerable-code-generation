//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateArray(int *array, int size);
void printArray(int *array, int size);
void bubbleSort(int *array, int size);
void quickSort(int *array, int low, int high);
int partition(int *array, int low, int high);

int main() {
    srand(time(NULL));   // Seed the random number generator
    
    int choice, size;
    printf("Welcome to the Sorting Simulator!\n");
    printf("How many random numbers would you like to sort? ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        perror("Unable to allocate memory for the array.");
        return EXIT_FAILURE;
    }

    generateArray(array, size);
    printf("\nGenerated Array:\n");
    printArray(array, size);

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    clock_t start, end;
    
    start = clock();  // Start measuring time
    switch (choice) {
        case 1:
            bubbleSort(array, size);
            break;
        case 2:
            quickSort(array, 0, size - 1);
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            free(array);
            return EXIT_FAILURE;
    }
    end = clock();  // Stop measuring time
    
    printf("\nSorted Array:\n");
    printArray(array, size);
    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorting completed in: %f seconds\n", time_spent);

    free(array);  // Free allocated memory
    return EXIT_SUCCESS;
}

// Function to generate an array of random integers
void generateArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;  // Random integers between 0 and 999
    }
}

// Function to print the array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to perform bubble sort
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to perform quick sort
void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);  // Recursively sort elements before partition
        quickSort(array, pi + 1, high); // Recursively sort elements after partition
    }
}

// Function to partition the array
int partition(int *array, int low, int high) {
    int pivot = array[high];  // Choosing the last element as pivot
    int i = (low - 1);        // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (array[j] <= pivot) {
            i++;  // Increment index of smaller element
            // Swap array[i] and array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Swap the pivot element with the element at index i + 1
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;  // Return the partitioning index
}