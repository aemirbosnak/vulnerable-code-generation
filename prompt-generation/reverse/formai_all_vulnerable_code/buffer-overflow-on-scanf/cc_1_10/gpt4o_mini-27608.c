//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to implement selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        // Find the minimum element in unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
        printf("🎉 Sorted up to index %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    printf("🌈 Current order of elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to execute the program
int main() {
    printf("🎈 Welcome to the Sorting Parade! 🎈\n");
    
    int n;
    printf("How many numbers do you want to sort? ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("🎉 Oops! Please enter a positive number! Let's start again.\n");
        return 1;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    
    // Input array elements from the user
    printf("🚀 Please enter %d numbers to sort: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("🔍 You entered: ");
    printArray(arr, n);
    
    selectionSort(arr, n);

    printf("🎊 Original List Sorted! 🎊\n");
    printArray(arr, n);
    
    // Free allocated memory
    free(arr);
    
    printf("🎉 Thank you for participating in the Sorting Parade! 🎉\n");
    return 0;
}