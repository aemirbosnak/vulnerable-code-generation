//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Function to swap two characters
void swap(char *xp, char *yp) {
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to partition the array
int partition(char arr[], int low, int high) {
    char pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    for (int j = low; j <= high - 1; j++) {
        // Compare and swap
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The quicksort function
void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

// Function to print the array
void printArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// Function to encode the sorted array based on Shannon's principles
void shannonEncode(char arr[], int size) {
    printf("Shannon Encoding of the sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("Character: %c, Code: ", arr[i]);
        for (int j = 0; j < i; j++) {
            printf("1");
        }
        printf("0\n"); // Each character ends with 0 as termination
    }
}

// Main function
int main() {
    char arr[MAX_LENGTH];
    printf("Enter characters to be sorted (end with new line):\n");
    fgets(arr, MAX_LENGTH, stdin); // Read input from user
    size_t length = strlen(arr);
    
    // Removing newline character from input
    if (arr[length - 1] == '\n') {
        arr[length - 1] = '\0';
        length--;
    }

    printf("Unsorted array: \n");
    printArray(arr, length);

    // Sorting the array using quicksort
    quickSort(arr, 0, length - 1);

    printf("Sorted array: \n");
    printArray(arr, length);
    
    // Encoding the sorted array using Shannon's approach
    shannonEncode(arr, length);

    return 0;
}