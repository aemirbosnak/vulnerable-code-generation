//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 1000
#define MAX_BUCKET_SIZE 10

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int i, j;
    int count[MAX_BUCKET_SIZE];
    for (i = 0; i < MAX_BUCKET_SIZE; i++) {
        count[i] = 0;
    }

    for (i = 0; i < size; i++) {
        (count[arr[i]])++;
    }

    for (i = 0, j = 0; i < MAX_BUCKET_SIZE; i++) {
        for(; count[i] > 0; (count[i])--) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int i, size;

    printf("Enter the total number of elements: ");
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] < 0 || arr[i] > MAX_BUCKET_SIZE) {
            printf("Invalid Input. Number must be between 0 and 9.\n");
            exit(0);
        }
    }

    printf("Input array is: ");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("Sorted array is: ");
    printArray(arr, size);
    
    return 0;
}