//Falcon-180B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Element arr[], int low, int high) {
    int pivot = arr[high].data;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > 0 && size <= MAX_SIZE) {
        printf("Enter %d integers:\n", size);
        for (int i = 0; i < size; i++) {
            arr[i].data = rand() % 100;
        }

        quickSort(arr, 0, size - 1);
        printf("Sorted array: \n");
        printArray(arr, size);
    } else {
        printf("Invalid array size.\n");
    }

    return 0;
}