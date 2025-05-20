//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data;
    int index;
} element;

void swap(element *a, element *b) {
    element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_elements(element arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Element %d: %d\n", i, arr[i].data);
    }
}

int partition(element arr[], int low, int high) {
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

void quickSort(element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    element arr[MAX];
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements: \n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quickSort(arr, 0, n - 1);

    printf("\nSorted elements: \n");
    print_elements(arr, n);

    return 0;
}