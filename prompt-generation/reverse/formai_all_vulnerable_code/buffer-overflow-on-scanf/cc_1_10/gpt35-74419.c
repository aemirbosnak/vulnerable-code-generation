//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to sort using bucket sort */
void bucket_sort(int arr[], int n, int max) {
    int i, j;
 
    // Create n buckets, each of size max
    int* bucket = (int*) malloc(n * sizeof(int));
    
    // Initialize all buckets to 0
    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }
    
    // Increment the corresponding bucket element for each element in the input array
    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }
    
    // Output the sorted array
    for (i = 0, j = 0; i < n; i++) {
        while (bucket[i] > 0) {
            arr[j++] = i;
            bucket[i]--;
        }
    }
    
    // Free the memory allocated for the buckets
    free(bucket);
}

int main() {
    int i, n, max, *arr;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Prompt the user for input
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    // Allocate memory for the array
    arr = (int*) malloc(n * sizeof(int));
    
    // Generate random input
    max = 0;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % n;
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Sort the array using bucket sort
    bucket_sort(arr, n, max + 1);
    
    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free the memory allocated for the array
    free(arr);
    
    return 0;
}