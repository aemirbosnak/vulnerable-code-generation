//Falcon-180B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to swap two strings
void swap(char* a, char* b) {
    char temp[MAX_SIZE];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Function to partition the array
int partition(char** arr, int low, int high) {
    char* pivot = arr[high];
    int i = low - 1;

    // Move the pivot element to its correct position
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            swap(arr[i + 1], arr[j]);
            i++;
        }
    }

    // Move the pivot element to its correct position
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Function to perform quicksort on the array
void quicksort(char** arr, int low, int high) {
    if (low < high) {
        // Partition the array
        int partitionIndex = partition(arr, low, high);

        // Recursively sort the left and right partitions
        quicksort(arr, low, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, high);
    }
}

// Function to print the sorted array
void printArray(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

// Function to read the array from the user
void readArray(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", arr[i]);
    }
}

// Main function
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    char** arr = (char**)malloc(size * sizeof(char*));

    // Read the array from the user
    readArray(arr, size);

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }

    // Sort the array using quicksort
    quicksort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    // Free the dynamically allocated memory
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}