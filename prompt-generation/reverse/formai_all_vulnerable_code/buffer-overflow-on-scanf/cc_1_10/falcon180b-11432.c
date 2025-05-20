//Falcon-180B DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} item;

int compare(const void *a, const void *b) {
    item *itemA = (item *)a;
    item *itemB = (item *)b;

    if (itemA->data > itemB->data) {
        return 1;
    } else if (itemA->data < itemB->data) {
        return -1;
    } else {
        return 0;
    }
}

void swap(item *a, item *b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(item arr[], int low, int high) {
    item pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot.data) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL));

    item arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }

    return 0;
}