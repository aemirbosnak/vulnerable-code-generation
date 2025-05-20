//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Element arr[], int low, int high) {
    int pivot = arr[high].data;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
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
            result = i;
            break;
        }
    }

    printf("The target element %d is found at index %d\n", target, result);
}

int main() {
    Element arr[MAX_SIZE];
    int n, target;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    search(arr, n, target);

    return 0;
}