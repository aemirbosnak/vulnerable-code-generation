//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Define the structure of a 2D array
typedef struct {
    int rows;
    int cols;
    int **array;
} Array2D;

// Function to initialize a 2D array
void initArray(Array2D *arr, int rows, int cols) {
    arr->rows = rows;
    arr->cols = cols;
    arr->array = (int **)malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++) {
        arr->array[i] = (int *)malloc(cols * sizeof(int));
    }
}

// Function to print a 2D array
void printArray(Array2D *arr) {
    for(int i=0; i<arr->rows; i++) {
        for(int j=0; j<arr->cols; j++) {
            printf("%d\t", arr->array[i][j]);
        }
        printf("\n");
    }
}

// Function to fill a 2D array with a pattern
void fillArray(Array2D *arr) {
    for(int i=0; i<arr->rows; i++) {
        for(int j=0; j<arr->cols; j++) {
            arr->array[i][j] = (i+j)%2;
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    Array2D arr;
    initArray(&arr, rows, cols);

    printf("Enter the elements of the array:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &arr.array[i][j]);
        }
    }

    printf("The filled array is:\n");
    fillArray(&arr);
    printArray(&arr);

    return 0;
}