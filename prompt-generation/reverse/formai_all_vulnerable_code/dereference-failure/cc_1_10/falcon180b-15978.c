//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int* buckets = (int*)malloc(MAX_SIZE*sizeof(int));
    for(int i=0; i<MAX_SIZE; i++) {
        buckets[i] = 0;
    }
    for(int i=0; i<n; i++) {
        int index = arr[i]/10;
        buckets[index]++;
    }
    for(int i=0; i<n; i++) {
        int index = arr[i]/10;
        buckets[index]--;
        arr[i] = index*10 + buckets[index];
    }
    free(buckets);
}

// Main function
int main() {
    int arr[] = {3, 7, 1, 9, 5, 2, 8, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("After sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}