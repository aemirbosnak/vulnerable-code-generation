//Falcon-180B DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int data;
    int index;
} pair;

void swap(pair* a, pair* b) {
    pair temp = *a;
    *a = *b;
    *b = temp;
}

int partition(pair* arr, int low, int high) {
    int pivot = arr[(low + high) / 2].data;
    pair temp = arr[(low + high) / 2];
    
    while (low <= high) {
        while (arr[low].data < pivot) {
            low++;
        }
        while (arr[high].data > pivot) {
            high--;
        }
        if (low <= high) {
            swap(&arr[low], &arr[high]);
            low++;
            high--;
        }
    }
    swap(&arr[low], &arr[(low + high) / 2]);
    return low;
}

void quicksort(pair* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void print_array(pair* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    pair* arr = (pair*)malloc(size * sizeof(pair));

    printf("Enter the elements of the array (data index):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &arr[i].data, &arr[i].index);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        swap(&arr[i], &arr[j]);
    }

    quicksort(arr, 0, size - 1);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}