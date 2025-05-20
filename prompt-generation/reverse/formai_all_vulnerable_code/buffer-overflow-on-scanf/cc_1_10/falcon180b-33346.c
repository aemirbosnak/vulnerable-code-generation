//Falcon-180B DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate a random matrix of given size
void generate_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Function to print a matrix
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose a matrix
void transpose_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int new_matrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            new_matrix[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = new_matrix[i][j];
        }
    }
}

// Main function
int main() {
    int size;
    printf("Enter matrix size (1-100): ");
    scanf("%d", &size);

    if (size < 1 || size > 100) {
        printf("Invalid matrix size!\n");
        return 1;
    }

    int matrix[MAX_SIZE][MAX_SIZE], new_matrix[MAX_SIZE][MAX_SIZE];

    // Generate random matrix
    generate_matrix(matrix, size);
    printf("Original matrix:\n");
    print_matrix(matrix, size);

    // Transpose matrix
    transpose_matrix(matrix, size);
    printf("Transposed matrix:\n");
    print_matrix(matrix, size);

    return 0;
}