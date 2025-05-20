//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value that an element could have
#define MAX_VALUE 10

void bucket_sort(int arr[], int n) {
    int i, j;
    int count[MAX_VALUE] = {0};

    // Count the number of times each element appears
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Print the original array
    printf("Original Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Traverse through each bucket and print the sorted elements
    printf("Bucket Sort: ");
    for (i = 0; i < MAX_VALUE; i++) {
        for (j = 0; j < count[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int i, n, *arr;
    
    // Ask the user for the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Allocate memory for the array
    arr = (int*) malloc(n * sizeof(int));
    
    // Ask the user for each element in the array
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the elements using Bucket Sort
    bucket_sort(arr, n);
    
    // Free the memory allocated for the array
    free(arr);

    return 0;
}