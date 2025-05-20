//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int random_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    return 0;
}

int identity_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    return 0;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Matrix is too large.\n");
        return 1;
    }

    int matrix[MAX_ROWS][MAX_COLS];

    int choice;
    printf("Enter 1 to generate a random matrix or 2 to generate an identity matrix: ");
    scanf("%d", &choice);

    if (choice == 1) {
        random_matrix(matrix, rows, cols);
        printf("Random matrix:\n");
    } else if (choice == 2) {
        identity_matrix(matrix, rows, cols);
        printf("Identity matrix:\n");
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}