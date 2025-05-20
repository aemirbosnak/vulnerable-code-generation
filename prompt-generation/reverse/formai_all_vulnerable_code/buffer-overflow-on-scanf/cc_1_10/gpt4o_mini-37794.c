//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void printIntro();
void printArray(int arr[], int size);
void fillArray(int arr[], int size);
void reverseArray(int arr[], int start, int end);

int main() {
    int size;
    
    printIntro();
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    if(size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    fillArray(arr, size);
    printf("\nOriginal Array:\n");
    printArray(arr, size);

    reverseArray(arr, 0, size - 1);
    
    printf("\nReversed Array:\n");
    printArray(arr, size);
    
    free(arr);
    return 0;
}

void printIntro() {
    printf("**********************************\n");
    printf("       Retro Array Reverser       \n");
    printf("   A small recursive C program!   \n");
    printf("**********************************\n");
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillArray(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void reverseArray(int arr[], int start, int end) {
    if (start >= end) {
        return; // Base case: if the start index crosses the end index, stop recursion
    }

    // Swap elements at start and end
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive call to reverse the inner sub-array
    reverseArray(arr, start + 1, end - 1);
}