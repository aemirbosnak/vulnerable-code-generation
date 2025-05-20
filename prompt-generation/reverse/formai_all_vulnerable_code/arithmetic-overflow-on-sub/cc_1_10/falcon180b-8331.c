//Falcon-180B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int data;
    int index;
} element;

void swap(element* a, element* b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

int compare(void* a, void* b) {
    element* elem1 = (element*) a;
    element* elem2 = (element*) b;
    if (elem1->data < elem2->data) {
        return -1;
    } else if (elem1->data == elem2->data) {
        return 0;
    } else {
        return 1;
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
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
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

void printarray(element* arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    element* arr = (element*) malloc(sizeof(element) * size);
    int i;
    for (i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    quicksort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printarray(arr, size);

    free(arr);
    return 0;
}