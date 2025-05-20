//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define BUCKETSIZE 10

// function to implement bucket sort
void bucketSort(int array[], int n) {
    // create an array of 10 buckets
    int bucket[BUCKETSIZE][n];
    // initialize all elements of bucket to 0
    for (int i = 0; i < BUCKETSIZE; i++) {
        for (int j = 0; j < n; j++) {
            bucket[i][j] = 0;
        }
    }
    // calculate maximum element in array
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    // calculate number of digits required to represent max
    int digits = 0;
    while (max > 0) {
        max /= 10;
        digits++;
    }
    // place elements in appropriate buckets
    for (int d = 0; d < digits; d++) {
        int divisor = (int) pow(10, d);
        for (int i = 0; i < n; i++) {
            int digit = (array[i] / divisor) % 10;
            bucket[digit][i] = array[i];
        }
    }
    // sort each bucket using insertion sort
    for (int i = 0; i < BUCKETSIZE; i++) {
        for (int j = 1; j < n; j++) {
            int key = bucket[i][j];
            int k = j - 1;
            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = key;
        }
    }
    // concatenate sorted elements from buckets into array
    int index = 0;
    for (int i = 0; i < BUCKETSIZE; i++) {
        for (int j = 0; j < n; j++) {
            if (bucket[i][j] != 0) {
                array[index++] = bucket[i][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n); // calling bucket sort function
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}