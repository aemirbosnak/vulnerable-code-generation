//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to do bucket sort 
void bucketSort(float arr[], int n) 
{ 
    // create n buckets 
    int i, j; 
    int count[n]; 
    for (i = 0; i < n; i++) 
        count[i] = 0; 

    // insert elements into the respective buckets 
    for (i = 0; i < n; i++) 
        count[(int)(arr[i] * n)]++; 

    // sort the elements in the buckets using insertion sort 
    for (i = 0; i < n; i++) 
        for (j = 0; j < count[i]; j++) 
            arr[count[i] - j - 1] = (float)i / n; 
} 

// function to print the array 
void printArray(float arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%f ", arr[i]); 
} 

int main() 
{ 
    // input the array 
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    float arr[n]; 
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    // perform bucket sort on the array 
    bucketSort(arr, n); 

    // print the sorted array 
    printf("\nSorted array: "); 
    printArray(arr, n); 

    return 0; 
}