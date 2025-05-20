//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    int index;
} element;

void swap(element *a, element *b) {
    element temp;
    temp.data = a->data;
    temp.index = a->index;
    a->data = b->data;
    a->index = b->index;
    b->data = temp.data;
    b->index = temp.index;
}

void heapify(element arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l].data > arr[largest].data)
        largest = l;

    if (r < n && arr[r].data > arr[largest].data)
        largest = r;

    if (largest!= i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(element arr[], int n) {
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    element arr[MAX];
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    heapsort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");

    return 0;
}