//Falcon-180B DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int data;
    int index;
} element;

void swap(element* a, element* b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    element* elem1 = (element*)a;
    element* elem2 = (element*)b;

    if (elem1->data < elem2->data) {
        return -1;
    } else if (elem1->data > elem2->data) {
        return 1;
    } else {
        return 0;
    }
}

void quicksort(element* arr, int left, int right) {
    int i = left, j = right;
    element pivot = arr[(left + right) / 2];
    element temp;

    while (i <= j) {
        while (compare(&arr[i], &pivot) < 0) {
            i++;
        }
        while (compare(&arr[j], &pivot) > 0) {
            j--;
        }
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quicksort(arr, left, j);
    }
    if (i < right) {
        quicksort(arr, i, right);
    }
}

int main() {
    element* arr = malloc(sizeof(element) * MAX_SIZE);
    int i, n;

    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i].data = rand() % MAX_SIZE;
        arr[i].index = i;
    }

    printf("Before sorting:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");

    quicksort(arr, 0, MAX_SIZE - 1);

    printf("After sorting:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");

    free(arr);
    return 0;
}