//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} element;

void swap(element *a, element *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    temp = a->index;
    a->index = b->index;
    b->index = temp;
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

int binarySearch(element arr[], int target, int size) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].data == target) {
            return mid;
        } else if (arr[mid].data < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    element arr[MAX_SIZE];
    int n, i, target, result;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    quickSort(arr, 0, n - 1);
    result = binarySearch(arr, target, n);
    if (result == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("Target value found at index %d.\n", result);
    }
    return 0;
}