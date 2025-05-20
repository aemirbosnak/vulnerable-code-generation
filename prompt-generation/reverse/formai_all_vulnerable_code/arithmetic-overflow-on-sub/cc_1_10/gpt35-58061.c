//FormAI DATASET v1.0 Category: Sorting ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 1000

/* Function to swap two integers */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to initialize an array with random integers */
void initialize_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_LENGTH + 1;
    }
}

/* Function to print an array */
void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to perform bubble sort on the given array */
void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/* Function to perform selection sort on the given array */
void selection_sort(int arr[], int n) {
    int min_index;
    for(int i = 0; i < n-1; i++) {
        min_index = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

/* Function to perform insertion sort on the given array */
void insertion_sort(int arr[], int n) {
    int j, key;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[MAX_LENGTH], n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    initialize_array(arr, n);
    printf("Original array: ");
    print_array(arr, n);
    
    bubble_sort(arr, n);
    printf("Array after bubble sort: ");
    print_array(arr, n);
    
    initialize_array(arr, n);
    printf("Original array: ");
    print_array(arr, n);
    
    selection_sort(arr, n);
    printf("Array after selection sort: ");
    print_array(arr, n);
    
    initialize_array(arr, n);
    printf("Original array: ");
    print_array(arr, n);
    
    insertion_sort(arr, n);
    printf("Array after insertion sort: ");
    print_array(arr, n);

    return 0;
}