//Falcon-180B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void handleError(char *errorMessage);
int **create2DArray(int rows, int cols);
void free2DArray(int **array, int rows);

// Main function
int main() {
    int rows, cols;
    int **array;

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Create 2D array
    array = create2DArray(rows, cols);

    // Fill array with random numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 100;
        }
    }

    // Print array
    printf("\nThe array is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free memory
    free2DArray(array, rows);

    return 0;
}

// Function to create 2D array
int **create2DArray(int rows, int cols) {
    int **array;
    array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }
    return array;
}

// Function to free memory of 2D array
void free2DArray(int **array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

// Function to handle errors
void handleError(char *errorMessage) {
    printf("Error: %s\n", errorMessage);
    exit(1);
}