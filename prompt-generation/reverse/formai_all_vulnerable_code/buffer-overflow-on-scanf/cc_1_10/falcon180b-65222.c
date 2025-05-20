//Falcon-180B DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} element;

void swap(element* a, element* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    
    temp = a->index;
    a->index = b->index;
    b->index = temp;
}

int partition(element* arr, int low, int high) {
    int pivot = arr[(low + high) / 2].data;
    element temp = arr[(low + high) / 2];
    
    arr[(low + high) / 2] = arr[high];
    arr[high] = temp;
    
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

void quicksort(element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printarray(element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    element arr[MAX_SIZE];
    int size;
    
    printf("enter the size of the array: ");
    scanf("%d", &size);
    
    srand(time(0));
    
    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }
    
    quicksort(arr, 0, size - 1);
    
    printf("sorted array:\n");
    printarray(arr, size);
    
    return 0;
}