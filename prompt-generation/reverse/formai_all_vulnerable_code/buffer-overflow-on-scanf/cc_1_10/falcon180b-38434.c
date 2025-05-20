//Falcon-180B DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int size;

void quickSort(int left, int right);
void swap(int *a, int *b);
int partition(int left, int right);

int main() {
    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(0, size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void quickSort(int left, int right) {
    if (left >= right)
        return;

    int pivotIndex = partition(left, right);

    quickSort(left, pivotIndex - 1);
    quickSort(pivotIndex + 1, right);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]);

    return i + 1;
}