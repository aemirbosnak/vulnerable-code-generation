//Falcon-180B DATASET v1.0 Category: Sorting ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of the element
typedef struct {
    int value;
    int index;
} Element;

// Define the function to swap two elements
void swap(Element* a, Element* b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
    
    temp = a->index;
    a->index = b->index;
    b->index = temp;
}

// Define the function to partition the array
int partition(Element* arr, int low, int high) {
    int pivot = arr[high].value;
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].value < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Define the function to sort the array
void quickSort(Element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Define the function to print the array
void printArray(Element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].value);
    }
    printf("\n");
}

// Define the main function
int main() {
    Element arr[MAX_SIZE];
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }
    
    quickSort(arr, 0, size - 1);
    
    printf("Sorted array:\n");
    printArray(arr, size);
    
    return 0;
}