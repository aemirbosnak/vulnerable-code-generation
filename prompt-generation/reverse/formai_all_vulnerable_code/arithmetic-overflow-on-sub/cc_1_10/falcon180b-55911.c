//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000 // Maximum size of the array

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
    int i = low - 1;

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

void search(Element arr[], int size, int target) {
    int result = -1;

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        if (arr[i].data == target) {
            result = arr[i].index;
            break;
        }
    }

    printf("Result: %d\n", result);
}

int main() {
    int size, target;
    Element arr[MAX_SIZE];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    search(arr, size, target);

    return 0;
}