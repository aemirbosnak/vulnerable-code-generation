//Falcon-180B DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements of an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition an array using the last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement quicksort algorithm
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Function to generate a random array of integers
int* generate_array(int size) {
    int* arr = (int*) malloc(size * sizeof(int));
    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}

// Function to print an array of integers
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to run the program
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = generate_array(size);
    print_array(arr, size);

    quick_sort(arr, 0, size - 1);
    print_array(arr, size);

    free(arr);
    return 0;
}