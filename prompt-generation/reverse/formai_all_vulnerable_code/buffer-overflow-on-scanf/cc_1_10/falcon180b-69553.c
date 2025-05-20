//Falcon-180B DATASET v1.0 Category: Sorting ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Pair;

void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Pair arr[], int left, int right) {
    int pivot = arr[(int) rand() % (right - left + 1) + left].data;
    swap(&arr[right], &arr[left]);
    int i = left;
    for (int j = left + 1; j <= right; j++) {
        if (arr[j].data < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

void quickSort(Pair arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

void printArray(Pair arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d %d\n", arr[i].data, arr[i].index);
    }
}

int main() {
    srand(time(NULL));
    Pair arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted Array:\n");
    printArray(arr, size);

    return 0;
}