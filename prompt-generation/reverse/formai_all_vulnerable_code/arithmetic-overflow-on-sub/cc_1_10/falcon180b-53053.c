//Falcon-180B DATASET v1.0 Category: Sorting ; Style: thoughtful
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
}

int partition(Element* arr, int low, int high) {
    int pivot = arr[(low + high) / 2].data;
    while (low <= high) {
        while (arr[low].data < pivot)
            low++;
        while (arr[high].data > pivot)
            high--;
        if (low <= high) {
            swap(&arr[low], &arr[high]);
            low++;
            high--;
        }
    }
    return low;
}

void quickSort(Element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(Element* arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i].data);
    printf("\n");
}

int main() {
    srand(time(NULL));
    Element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    printf("Before sorting:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("After sorting:\n");
    printArray(arr, size);

    return 0;
}