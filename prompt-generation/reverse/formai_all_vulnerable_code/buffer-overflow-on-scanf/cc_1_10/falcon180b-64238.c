//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int n = size;
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int *)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int index = arr[i] - min;
        bucket[index]++;
    }
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i] > 0) {
            arr[j++] = i + min;
            bucket[i]--;
        }
    }
    free(bucket);
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
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int randomIndex = rand() % size;
        int temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
    printf("Original array:\n");
    printArray(arr, size);
    bucketSort(arr, size);
    printf("Sorted array:\n");
    printArray(arr, size);
    return 0;
}