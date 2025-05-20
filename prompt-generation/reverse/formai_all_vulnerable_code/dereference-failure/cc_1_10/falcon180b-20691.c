//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

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
    int bucketSize = max/n;
    int numBuckets = max/bucketSize + 1;
    int* buckets = (int*) malloc(numBuckets * sizeof(int));
    for(int i=0; i<numBuckets; i++) {
        buckets[i] = 0;
    }
    for(int i=0; i<n; i++) {
        int bucketIndex = arr[i]/bucketSize;
        buckets[bucketIndex]++;
    }
    for(int i=0; i<n; i++) {
        int bucketIndex = arr[i]/bucketSize;
        buckets[bucketIndex]--;
        int j = buckets[bucketIndex];
        arr[j] = arr[i];
        j++;
        while(j < n && (arr[j]/bucketSize) == bucketIndex) {
            j++;
        }
        i = j;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 3, 5, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}