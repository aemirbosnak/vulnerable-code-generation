//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000 // maximum size of the array

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int* buckets = (int*) malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int index = arr[i] - min;
        buckets[index]++;
    }
    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i + min;
        }
    }
    free(buckets);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int seed;
    printf("Enter the seed for the random number generator: ");
    scanf("%d", &seed);
    srand(seed);
    for (int i = 0; i < size; i++) {
        int index = rand() % size;
        swap(&arr[i], &arr[index]);
    }
    printf("Original array: ");
    printArray(arr, size);
    bucketSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}