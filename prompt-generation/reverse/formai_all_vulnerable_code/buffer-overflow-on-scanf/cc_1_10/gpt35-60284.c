//FormAI DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int size){
    int temp;
    int i, j;

    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *arr, int size){
    int i, j, temp, min_index;

    for(i = 0; i < size - 1; i++){
        min_index = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertion_sort(int *arr, int size){
    int i, j, key;

    for(i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void print_array(int *arr, int size){
    int i;

    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(){
    int size, i;
    int *arr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    // Allocate memory for array
    arr = (int*)malloc((size) * sizeof(int));

    // Initialize array
    srand(time(NULL));
    for(i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }

    printf("Original array: ");
    print_array(arr, size);

    // Sort array using bubble sort
    bubble_sort(arr, size);
    printf("Array after bubble sort: ");
    print_array(arr, size);

    // Sort array using selection sort
    selection_sort(arr, size);
    printf("Array after selection sort: ");
    print_array(arr, size);

    // Sort array using insertion sort
    insertion_sort(arr, size);
    printf("Array after insertion sort: ");
    print_array(arr, size);

    // Free memory allocated for array
    free(arr);

    return 0;
}