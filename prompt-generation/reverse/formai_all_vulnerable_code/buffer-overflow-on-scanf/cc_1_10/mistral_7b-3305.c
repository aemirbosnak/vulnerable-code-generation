//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} element;

void swap(element* a, element* b) {
    int temp = a->index;
    a->index = b->index;
    b->index = temp;
}

void selection_sort(element arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].data < arr[min_idx].data) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

int main() {
    element arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    selection_sort(arr, n);

    printf("\nSorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }

    printf("\nSorted index: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].index);
    }

    return 0;
}