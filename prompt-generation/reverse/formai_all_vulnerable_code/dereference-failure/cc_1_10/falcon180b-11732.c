//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void bucketSort(int *array, int size);
void insertionSort(int *array, int size);
void printArray(int *array, int size);

int main(int argc, char *argv[]) {
    int i, j;
    int *array;
    clock_t start, end;

    srand(time(NULL));

    array = (int *) malloc(SIZE * sizeof(int));

    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % SIZE;
    }

    start = clock();
    bucketSort(array, SIZE);
    end = clock();

    printf("Bucket Sort took %.6f seconds.\n", (double) (end - start) / CLOCKS_PER_SEC);

    printArray(array, SIZE);

    free(array);
    return 0;
}

void bucketSort(int *array, int size) {
    int i, j, k;
    int *bucket[SIZE];

    for (i = 0; i < SIZE; i++) {
        bucket[i] = (int *) malloc(sizeof(int));
    }

    for (i = 0; i < size; i++) {
        k = array[i] * SIZE / (int) SIZE;
        bucket[k] = (int *) realloc(bucket[k], sizeof(int) * (1 + bucket[k][0]));
        bucket[k][bucket[k][0]] = array[i];
        bucket[k][0]++;
    }

    for (i = 0; i < SIZE; i++) {
        insertionSort(bucket[i], bucket[i][0]);
    }

    for (i = 0; i < size; i++) {
        array[i] = bucket[(int) (array[i] * SIZE / (int) SIZE)][0];
    }

    for (i = 0; i < SIZE; i++) {
        free(bucket[i]);
    }
}

void insertionSort(int *array, int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void printArray(int *array, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}