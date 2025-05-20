//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *data;
    int size;
} Array;

void initializeArray(Array *array, int size) {
    array->data = (int *) malloc(size * sizeof(int));
    array->size = size;
}

void printArray(Array array) {
    int i;
    for (i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(Array array, int low, int high) {
    int i = low, j = high;
    int pivot = array.data[(low + high) / 2];

    while (i <= j) {
        while (array.data[i] > pivot)
            i++;
        while (array.data[j] < pivot)
            j--;
        if (i <= j) {
            swap(&array.data[i], &array.data[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quicksort(array, low, j);
    if (i < high)
        quicksort(array, i, high);
}

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Array array;
    initializeArray(&array, size);

    int i;
    for (i = 0; i < size; i++) {
        array.data[i] = rand() % 100;
    }

    printf("Unsorted array:\n");
    printArray(array);

    quicksort(array, 0, size - 1);

    printf("Sorted array:\n");
    printArray(array);

    return 0;
}