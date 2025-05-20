//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n);
void swap(int *xp, int *yp);

int main() 
{ 
    int i, n;

    // Take input from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Create an array of integers
    int arr[n];

    // Fill the array with some random values
    for (i=0; i<n; i++) 
    { 
        arr[i] = rand() % 100; 
    } 

    // Call function to sort the array
    bubbleSort(arr, n); 

    // Print the sorted array
    for (i=0; i<n; i++) 
        printf("%d ", arr[i]); 

    return 0; 
} 

void bubbleSort(int arr[], int n) 
{ 
    int i, j, temp; 

    // Outer loop traverses through all array elements 
    for (i=0; i<n-1; i++) 
    { 
        // Inner loop compares adjacent elements 
        // and swaps if they are in wrong order 
        for (j=0; j<n-i-1; j++) 
        { 
            if (arr[j] > arr[j+1]) 
            { 
                temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            } 
        } 
    } 
} 

void swap(int *xp, int *yp) 
{ 
    int temp; 
    temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}