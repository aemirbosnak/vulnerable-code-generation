//Falcon-180B DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Element;

void swap(Element arr[], int i, int j) {
    Element temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printArray(Element arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

void selectionSort(Element arr[], int size) {
    int i, j, minIndex;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < size; j++) {
            if (arr[j].data < arr[minIndex].data) {
                minIndex = j;
            }
        }

        swap(arr, i, minIndex);
    }
}

int main() {
    srand(time(NULL));

    Element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size!\n");
        return -1;
    }

    printf("Enter %d integers:\n", size);

    int i;
    for (i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    printf("Unsorted array:\n");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}