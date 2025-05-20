//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void bucketSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("After sorting:\n");
    printArray(arr, n);
    return 0;
}

void bucketSort(int arr[], int n) {
    int i, j;
    int *bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *) malloc(MAX_SIZE * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        int index = arr[i] * MAX_SIZE / (n - 1);
        bucket[index] = (int *) realloc(bucket[index], sizeof(int) * (n - i + 1));
        bucket[index][n - i - 1] = arr[i];
    }
    for (i = 0; i < n; i++) {
        int index = arr[i] * MAX_SIZE / (n - 1);
        for (j = 0; j <= n - i - 1; j++) {
            arr[i + j] = bucket[index][j];
        }
    }
    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}