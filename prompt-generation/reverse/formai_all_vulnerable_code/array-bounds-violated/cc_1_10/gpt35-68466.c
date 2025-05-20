//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define BUCKET_SIZE 5

void bucketSort(int arr[], int n);
int compare(const void* a, const void* b);

int main() {
    int arr[ARRAY_SIZE] = {43, 59, 10, 83, 77, 25, 39, 61, 91, 17};

    printf("Unsorted array: ");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, ARRAY_SIZE);

    printf("\nSorted array: ");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucketSort(int arr[], int n) {
    int bucket[BUCKET_SIZE][ARRAY_SIZE] = {0};

    for(int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - 1) / BUCKET_SIZE;
        int bucketPosition = 0;

	while(bucket[bucketIndex][bucketPosition] != 0 && bucket[bucketIndex][bucketPosition] < arr[i]) {
            bucketPosition++;
        }

        for(int j = n - 1; j >= bucketPosition; j--) {
            bucket[bucketIndex][j + 1] = bucket[bucketIndex][j];
        }

        bucket[bucketIndex][bucketPosition] = arr[i];
    }

    for(int i = 0; i < BUCKET_SIZE; i++) {
        qsort(bucket[i], ARRAY_SIZE, sizeof(int), compare);
    }

    int index = 0;
    for(int i = 0; i < BUCKET_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE; j++) {
            if(bucket[i][j] != 0) {
                arr[index++] = bucket[i][j];
            }
        }
    }
}

int compare(const void* a, const void* b) {  
    return (*(int*)a - *(int*)b);  
}