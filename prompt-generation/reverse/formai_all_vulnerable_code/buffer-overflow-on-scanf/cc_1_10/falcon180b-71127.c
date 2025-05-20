//Falcon-180B DATASET v1.0 Category: Sorting ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    int data;
    int pos;
} node;

void swap(node* a, node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;

    temp = a->pos;
    a->pos = b->pos;
    b->pos = temp;
}

int partition(node arr[], int low, int high) {
    int pivot = arr[(int)rand() % (high - low + 1) + low].data;
    node temp = arr[high];

    arr[high] = arr[low];
    arr[low].pos = high;
    arr[low].data = pivot;
    arr[high].pos = low;
    arr[high].data = temp.data;
    arr[high].pos = temp.pos;

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quicksort(node arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printarray(node arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    node arr[n];

    for (int i = 0; i < n; i++) {
        arr[i].data = rand() % 100;
        arr[i].pos = i;
    }

    srand(time(0));
    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    printarray(arr, n);

    return 0;
}