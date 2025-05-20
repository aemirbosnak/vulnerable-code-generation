//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>

/*
 * This program sorts an array of integers in ascending order using the selection sort algorithm
 * The user inputs the length of the array and then inputs the elements of the array
 * The program then outputs the sorted array
 */

int main() {
    int n; // length of the array
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    
    int arr[n]; // array of integers
    int i, j, temp; // loop variables and temporary variable
    
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nUnsorted Array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    // sorting algorithm
    for(i=0; i<n-1; i++) {
        int min_index = i; // assume the minimum element is at index i
        
        for(j=i+1; j<n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j; // update the minimum index
            }
        }
        
        // swap the minimum element with the ith element
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    
    printf("\nSorted Array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}