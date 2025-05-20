//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct {
    int *data;
    int size;
} Array;

Array createArray(int size) {
    Array arr;
    arr.data = (int *)malloc(size * sizeof(int));
    arr.size = size;
    for (int i = 0; i < size; i++) {
        arr.data[i] = rand() % 100; // Fill array with random values
    }
    return arr;
}

void freeArray(Array *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
}

void printArray(const Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

double calculateMean(const Array *arr) {
    double sum = 0.0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->data[i];
    }
    return sum / arr->size;
}

double calculateVariance(const Array *arr, double mean) {
    double variance = 0.0;
    for (int i = 0; i < arr->size; i++) {
        variance += (arr->data[i] - mean) * (arr->data[i] - mean);
    }
    return variance / arr->size;
}

double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Array *arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                swap(&arr->data[j], &arr->data[j + 1]);
            }
        }
    }
}

void displayStatistics(const Array *arr) {
    double mean = calculateMean(arr);
    double variance = calculateVariance(arr, mean);
    double stddev = calculateStandardDeviation(variance);

    printf("Statistics:\n");
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);
}

int main() {
    srand(time(NULL));
    int size;

    printf("Enter the size of the array (1 to 100): ");
    scanf("%d", &size);

    if (size < 1 || size > MAX) {
        printf("Invalid array size! Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    Array arr = createArray(size);
    printf("Generated Array:\n");
    printArray(&arr);

    bubbleSort(&arr);
    printf("Sorted Array:\n");
    printArray(&arr);

    displayStatistics(&arr);

    freeArray(&arr);
    return 0;
}