//Falcon-180B DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int data;
    int index;
} element;

void swap(element* a, element* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    temp = a->index;
    a->index = b->index;
    b->index = temp;
}

int partition(element* arr, int low, int high) {
    element pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot.data) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void print_array(element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quicksort(arr, 0, size - 1);

    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}