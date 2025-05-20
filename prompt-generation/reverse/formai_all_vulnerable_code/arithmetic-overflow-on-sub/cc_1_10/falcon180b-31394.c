//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

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

int partition(Element arr[], int low, int high) {
    Element pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot.data) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
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
    int i;
    for (i=0; i < size; i++) {
        printf("Element %d: Data = %d, Index = %d\n", i, arr[i].data, arr[i].index);
    }
}

int main() {
    Element arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i=0; i<n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quickSort(arr, 0, n-1);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}