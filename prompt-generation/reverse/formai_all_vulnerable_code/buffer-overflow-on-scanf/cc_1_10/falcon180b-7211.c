//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum elements in the array
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range and the size of each bucket
    int range = max - min;
    int bucketSize = range / n;

    // Create an empty array of buckets
    int buckets[n];
    for(int i=0; i<n; i++) {
        buckets[i] = -1;
    }

    // Put each element in its corresponding bucket
    for(int i=0; i<n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        if(buckets[bucketIndex] == -1) {
            buckets[bucketIndex] = i;
        }
        else {
            int j = buckets[bucketIndex];
            while(j!= -1) {
                j = (j + 1) % n;
            }
            buckets[bucketIndex] = j;
        }
    }

    // Concatenate the sorted buckets back into the original array
    int k = 0;
    for(int i=0; i<n; i++) {
        if(buckets[i]!= -1) {
            arr[k++] = arr[buckets[i]];
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}