//Falcon-180B DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    temp = a->index;
    a->index = b->index;
    b->index = temp;
}

int partition(Element arr[], int low, int high) {
    Element pivot = arr[high];
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

void quicksort(Element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printArray(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    Element arr[MAX_SIZE];

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}