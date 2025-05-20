//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int low, int high) {
    int i, j, pivot;

    if (low < high) {
        pivot = partition(arr, low, high);
        sort(arr, low, pivot - 1);
        sort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int i, len;
    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &len);

    for (i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }

    printf("Original array: \n");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort(arr, 0, len - 1);

    printf("Sorted array: \n");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}