//Falcon-180B DATASET v1.0 Category: Educational ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// function prototypes
int *create_array(int size);
void print_array(int *arr, int size);
void reverse_array(int *arr, int size);
void sort_array(int *arr, int size);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = create_array(size);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Original array:\n");
    print_array(arr, size);

    reverse_array(arr, size);
    printf("\nArray after reversing:\n");
    print_array(arr, size);

    sort_array(arr, size);
    printf("\nArray after sorting:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}

// creates an integer array of given size and returns a pointer to it
int *create_array(int size) {
    int *arr = (int *) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    return arr;
}

// prints the elements of an integer array
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// reverses the elements of an integer array
void reverse_array(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// sorts an integer array in ascending order
void sort_array(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}