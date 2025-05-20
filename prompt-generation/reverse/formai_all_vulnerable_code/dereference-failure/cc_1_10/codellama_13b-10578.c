//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory for a 2D array
int** allocate_2D_array(int rows, int cols) {
    int** arr = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(cols * sizeof(int));
    }
    return arr;
}

// Function to deallocate memory for a 2D array
void deallocate_2D_array(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

// Function to print a 2D array
void print_2D_array(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Allocate a 2D array with 3 rows and 4 columns
    int** arr = allocate_2D_array(3, 4);

    // Fill the array with values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = i * 4 + j;
        }
    }

    // Print the array
    print_2D_array(arr, 3, 4);

    // Deallocate the array
    deallocate_2D_array(arr, 3);

    return 0;
}