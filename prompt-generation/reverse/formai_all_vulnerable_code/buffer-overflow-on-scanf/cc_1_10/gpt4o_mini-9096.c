//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ELEMENTS 20

void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);

int main() {
    int array[MAX_ELEMENTS];
    int n, i;

    // Artistic Introduction
    printf("\n===========================\n");
    printf("   Artistic Bubble Sort    \n");
    printf("===========================\n");
    printf("Enter the number of elements (max %d): ", MAX_ELEMENTS);
    scanf("%d", &n);

    if (n > MAX_ELEMENTS) {
        printf("Exceeds maximum allowed elements. Please try again.\n");
        return 1;
    }

    // Generate random artistic elements
    printf("Creating an array of %d artistic elements:\n", n);
    for (i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }

    // Display original array
    printf("Original array:\n");
    printArray(array, n);

    // Start sorting and display progress
    printf("\nSorting...\n");
    bubbleSort(array, n);

    // Display sorted array
    printf("Sorted array:\n");
    printArray(array, n);
    
    // Artistic Ending
    printf("\n===========================\n");
    printf("     Sorting Complete!     \n");
    printf("===========================\n");

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            // Display sorting progress
            printf("\rSorting: ");
            printArray(arr, size);
            fflush(stdout);
            usleep(500000); // Sleep for a while to visualize progress
        }
    }
}