//FormAI DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void print_array(int arr[], int n);

int main() {
    int choice, n, i;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    int *arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d elements: \n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nChoose a sorting algorithm to sort the array: \n");
    printf("1. Insertion sort\n");
    printf("2. Selection sort\n");
    printf("3. Bubble sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            insertion_sort(arr, n);
            printf("\nSorted array using insertion sort: ");
            print_array(arr, n);
            break;
        case 2:
            selection_sort(arr, n);
            printf("\nSorted array using selection sort: ");
            print_array(arr, n);
            break;
        case 3:
            bubble_sort(arr, n);
            printf("\nSorted array using bubble sort: ");
            print_array(arr, n);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    // Free the dynamically allocated memory
    free(arr);
    
    return 0;
}

// Insertion Sort
void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; 
    }
}

// Selection Sort
void selection_sort(int arr[], int n) {
    int i, j, temp, min_index;
    for(i = 0; i < n-1; i++) {
        min_index = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Bubble Sort
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to print the array
void print_array(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}