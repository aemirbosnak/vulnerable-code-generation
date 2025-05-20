//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define RANGE 1000000

int main() {
    int i, j, n, max = 0, min = RANGE;
    int *arr;
    double start, end;

    //initialize the array with random values
    arr = (int *)malloc(SIZE * sizeof(int));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % RANGE;
    }

    //find the minimum and maximum values in the array
    for (i = 0; i < SIZE; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    //calculate the range of the array
    int range = max - min + 1;

    //allocate memory for the buckets
    int *buckets = (int *)malloc(range * sizeof(int));

    //initialize the buckets to zero
    for (i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    //place the elements in the appropriate buckets
    for (i = 0; i < SIZE; i++) {
        int index = (arr[i] - min) / RANGE;
        buckets[index]++;
    }

    //place the elements back in the array
    for (i = 0; i < SIZE; i++) {
        int index = (arr[i] - min) / RANGE;
        arr[i] = min + index * RANGE;
    }

    //sort the array using insertion sort
    for (i = 1; i < SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    //print the sorted array
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //free the memory
    free(arr);
    free(buckets);

    return 0;
}