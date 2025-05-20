//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucket_size = range / n;

    int* bucket[n];

    for (int i = 0; i < n; i++) {
        bucket[i] = (int*)malloc(bucket_size * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            bucket[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min) / bucket_size;
        bucket[index][(arr[i] - min) % bucket_size]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            int k = j;
            while (bucket[i][k] > 0) {
                arr[i * bucket_size + j] = min + j * bucket_size;
                bucket[i][k]--;
                k++;
            }
        }
    }
}

// Function to generate random integers
void generateRandomIntegers(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
    }
}

// Main function
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    generateRandomIntegers(arr, n);

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}