//Falcon-180B DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
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
    int pivot = arr[(low + high) / 2].data;
    while (low <= high) {
        while (arr[low].data < pivot)
            low++;
        while (arr[high].data > pivot)
            high--;
        if (low <= high) {
            swap(arr, low, high);
            low++;
            high--;
        }
    }
    return low;
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
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    Element arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");

    return 0;
}