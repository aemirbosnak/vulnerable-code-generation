//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

int generateRandomNumber() {
    return rand() % MAX_SIZE;
}

void bucketSort(int arr[], int size) {
    int i, j, index;
    int *bucket[BUCKET_SIZE];
    
    for (i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * size);
    }
    
    for (i = 0; i < size; i++) {
        index = arr[i] / BUCKET_SIZE;
        bucket[index] = realloc(bucket[index], sizeof(int) * (size + 1));
        bucket[index][size] = arr[i];
    }
    
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < size; j++) {
            arr[j] = bucket[i][j];
        }
    }
    
    for (i = 0; i < BUCKET_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int i, size;
    int *arr;
    
    srand(time(NULL));
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    arr = (int *)malloc(sizeof(int) * size);
    
    for (i = 0; i < size; i++) {
        arr[i] = generateRandomNumber();
    }
    
    printf("Original array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bucketSort(arr, size);
    
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    
    return 0;
}