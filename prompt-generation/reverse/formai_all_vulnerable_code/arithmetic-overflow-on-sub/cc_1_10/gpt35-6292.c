//FormAI DATASET v1.0 Category: Memory management ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

void allocate_array(int **arr, int size) {
    // Allocate memory for array of size given
    *arr = (int*)malloc(size * sizeof(int));
    
    // Check if allocation was successful
    if(*arr == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
}

void initialize_array(int *arr, int size) {
    // Initialize array with random values
    srand(time(NULL));
    for(int i=0; i<size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int *arr, int size) {
    printf("[");
    for(int i=0; i<size; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");
}

void deallocate_array(int *arr) {
    free(arr);
}

int main() {
    int size;
    int *arr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    // Allocate memory for array of given size
    allocate_array(&arr, size);

    // Initialize array with random values
    initialize_array(arr, size);

    // Print array
    printf("Array before sorting:\n");
    print_array(arr, size);

    // Sort array (bubble sort)
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print sorted array
    printf("Array after sorting:\n");
    print_array(arr, size);

    // Deallocate memory for array
    deallocate_array(arr);

    return 0;
}