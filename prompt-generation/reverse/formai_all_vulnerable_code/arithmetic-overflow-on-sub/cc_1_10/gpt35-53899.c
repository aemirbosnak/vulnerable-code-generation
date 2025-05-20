//FormAI DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int* arr = (int*) malloc(n * sizeof(int));

    // Populate the array with user input values
    for(i = 0; i < n; i++){
        printf("Enter value for index %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    // Allocate memory for a new array to store the sorted values
    int* sorted_arr = (int*) malloc(n * sizeof(int));

    // Sort the original array using a simple bubble sort algorithm
    for(i = 0; i < n-1; i++){
        int j, temp, sorted = 1;
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                sorted = 0;
                // Swap values
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(sorted == 1){
            break;
        }
    }

    // Print the sorted array
    printf("\nSorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
        sorted_arr[i] = arr[i]; // Copy sorted values to new array
    }

    // Deallocate memory for the original array
    free(arr);

    // Allocate memory for a new array to store the reversed values
    int* reversed_arr = (int*) malloc(n * sizeof(int));

    // Reverse the sorted array
    for(i = 0; i < n; i++){
        reversed_arr[i] = sorted_arr[n-i-1];
    }

    // Print the reversed array
    printf("\nReversed array: ");
    for(i = 0; i < n; i++){
        printf("%d ", reversed_arr[i]);
    }

    // Deallocate memory for the sorted array and reversed array
    free(sorted_arr);
    free(reversed_arr);

    return 0;
}