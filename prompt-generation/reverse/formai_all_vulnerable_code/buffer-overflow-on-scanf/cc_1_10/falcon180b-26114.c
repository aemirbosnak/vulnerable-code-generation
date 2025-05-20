//Falcon-180B DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int pivot = arr[(int) rand() % (high - low + 1) + low].data;
    element temp = arr[high];
    arr[high] = arr[low];
    arr[low] = temp;
    
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

void printArray(element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    element arr[MAX_SIZE];
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }
    
    srand(time(NULL));
    quickSort(arr, 0, n - 1);
    
    printf("Sorted array:\n");
    printArray(arr, n);
    
    return 0;
}