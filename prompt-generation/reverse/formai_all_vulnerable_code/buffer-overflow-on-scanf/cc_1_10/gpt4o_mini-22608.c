//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);
void fillRandomNumbers(int arr[], int size);

int main() {
    int size;
    printf("🎉 Welcome to the Ultimate Sorting Experience! 🎉\n");
    printf("How many random numbers would you like to sort? ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    
    printf("Generating %d random numbers...\n", size);
    fillRandomNumbers(arr, size);
    
    printf("🌈 Here are your randomly generated numbers: \n");
    printArray(arr, size);

    clock_t start, end;
    start = clock();
    
    // Quick Sort begins!
    printf("\n🔄 Performing Quick Sort...\n");
    quickSort(arr, 0, size - 1);
    
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("🔍 Your sorted numbers are: \n");
    printArray(arr, size);
    printf("⏳ Sorting completed in %.6f seconds.\n", time_taken);

    free(arr);
    printf("Thanks for using the Ultimate Sorting Experience! 🌟\n");
    return 0;
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1); // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

// Function to partition the array based on pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as pivot
    int i = (low - 1); // Place for the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // If current element is smaller than or equal to pivot
            i++; // Increment the index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Function to fill the array with random numbers
void fillRandomNumbers(int arr[], int size) {
    srand(time(0)); // Seed for random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Fill with random numbers from 0 to 999
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}