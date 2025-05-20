//Falcon-180B DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} element;

// Function to swap two elements
void swap(element* a, element* b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(element* arr, int low, int high) {
    int pivot = arr[high].data;
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

// Function to perform quicksort
void quicksort(element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to generate random numbers
void generate_random_numbers(element* arr, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }
}

// Function to print the array
void print_array(element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size too large!\n");
        return 1;
    }

    generate_random_numbers(arr, size);
    printf("Unsorted array:\n");
    print_array(arr, size);

    quicksort(arr, 0, size - 1);
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}