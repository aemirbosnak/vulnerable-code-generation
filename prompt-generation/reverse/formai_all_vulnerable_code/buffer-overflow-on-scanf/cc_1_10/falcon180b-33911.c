//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int size) {
    int i, j, max, min, range, count[MAX_SIZE] = {0};
    int *output = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        count[(arr[i] * MAX_SIZE) / (max = arr[0])]++;
    }

    for (i = 1; i < MAX_SIZE; i++) {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--) {
        output[--count[(arr[i] * MAX_SIZE) / max]] = arr[i];
    }

    for (i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    free(output);
}

int main() {
    int size, i;
    time_t start, end;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Initialize the array with random values
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }

    start = clock();
    bucketSort(arr, size);
    end = clock();

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}