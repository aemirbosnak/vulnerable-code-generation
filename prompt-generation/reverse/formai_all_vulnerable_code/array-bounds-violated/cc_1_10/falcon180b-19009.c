//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, sum = 0;
    clock_t start, end;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    // Initialize random array of size n
    int arr[n];
    for(i=0; i<n; i++) {
        arr[i] = rand() % n;
    }
    
    // Sort the array using bubble sort
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // Calculate sum of array elements
    for(i=0; i<n; i++) {
        sum += arr[i];
    }
    
    // Calculate time taken for sorting
    start = clock();
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    
    // Print sorted array and time taken for sorting
    printf("\nSorted array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken for sorting: %lf seconds\n", time_taken);
    
    return 0;
}