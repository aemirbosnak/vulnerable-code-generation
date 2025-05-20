//Falcon-180B DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

// Function to generate random matrix
void generate_matrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Function to print matrix
void print_matrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find maximum value in matrix
int find_max(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int max = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[MAX_ROWS][MAX_COLS];
    generate_matrix(rows, cols, matrix);
    print_matrix(rows, cols, matrix);

    int max = find_max(rows, cols, matrix);
    printf("Maximum value in matrix: %d\n", max);

    return 0;
}