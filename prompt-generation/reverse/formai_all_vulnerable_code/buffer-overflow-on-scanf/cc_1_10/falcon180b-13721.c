//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_array(int arr[], int size);
int *create_array(int size);
void delete_array(int *arr);

// Main function
int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = create_array(size);

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    print_array(arr, size);

    delete_array(arr);

    return 0;
}

// Function to print the elements of an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to create an integer array of given size
int *create_array(int size) {
    int *arr = (int *) malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    return arr;
}

// Function to delete an integer array
void delete_array(int *arr) {
    free(arr);
}