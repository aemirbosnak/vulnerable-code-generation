//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the maximum values for input array and bucket size.
#define MAX_VAL 100
#define BUCKET_SIZE 10

// Define the bucket sort function.
void bucketSort(int arr[], int n){
    int i, j, k;
 
    // Create buckets and initialize them all to 0.
    int buckets[BUCKET_SIZE];
    for (i = 0; i < BUCKET_SIZE; i++){
        buckets[i] = 0;
    }
 
    // Store the count of each element in the input array.
    for (i = 0; i < n; i++){
        ++buckets[arr[i]];
    }
 
    // Sort the elements in each bucket using insertion sort.
    for (i = 0, j = 0; j < BUCKET_SIZE; ++j){
        for (k = buckets[j]; k > 0; --k){
            arr[i++] = j;
        }
    }
}

int main() {
    int arr[MAX_VAL];
    int n;
    
    // Ask the user for input array size.
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    // Get the input array values.
    printf("Enter %d elements in the array: ", n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    // Call the bucket sort function.
    bucketSort(arr, n);
    
    // Display the sorted array.
    printf("Sorted Array:");
    for(int i=0;i<n;i++){
        printf(" %d", arr[i]);
    }
    
    return 0;
}