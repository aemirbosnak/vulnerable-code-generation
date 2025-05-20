//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void bucketSort(int arr[], int size) {
    int i, j, min, max;
    int bucket[MAX_SIZE];
    int *temp;

    max = arr[0];
    min = arr[0];

    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    temp = (int *) malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 0; i < size; i++) {
        bucket[arr[i] - min]--;
        arr[i] = min + bucket[arr[i] - min];
    }

    free(temp);
}

void printArray(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, size;
    int arr[MAX_SIZE];

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");

    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting:\n");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("Array after sorting:\n");
    printArray(arr, size);

    return 0;
}