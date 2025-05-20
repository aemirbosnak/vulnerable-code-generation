//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    int index;
    float value;
} ValuePair;

void swap(ValuePair* a, ValuePair* b) {
    ValuePair temp = *a;
    *a = *b;
    *b = temp;
}

int partition(ValuePair arr[], int low, int high) {
    ValuePair pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].value < pivot.value) {
            swap(&arr[i + 1], &arr[j]);
            i++;
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(ValuePair arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    ValuePair arr[MAX_SIZE];
    int n;
    int i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        arr[i].index = i;
        arr[i].value = rand() % 100;
    }

    clock_t start = clock();
    quicksort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %f\n", arr[i].index, arr[i].value);
    }

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", duration);

    return 0;
}