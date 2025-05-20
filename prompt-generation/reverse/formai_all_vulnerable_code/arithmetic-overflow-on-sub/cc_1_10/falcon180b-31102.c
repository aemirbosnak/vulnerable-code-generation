//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the array

typedef struct {
    int data;
    int index;
} element;

void swap(element* a, element* b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(element arr[], int low, int high) {
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

void quickSort(element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void search(element arr[], int size, int target) {
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
    int n, target;
    scanf("%d", &n);

    element arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    scanf("%d", &target);

    search(arr, n, target);

    return 0;
}