//Falcon-180B DATASET v1.0 Category: Educational ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NUMBERS 50

void generate_random_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % MAX_NUMBERS;
        }
    }
}

void print_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Matrix dimensions are too large.\n");
        return 1;
    }

    int matrix[MAX_ROWS][MAX_COLS];
    generate_random_matrix(matrix, rows, cols);
    printf("Random matrix:\n");
    print_matrix(matrix, rows, cols);

    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Sum of all elements: %d\n", sum);

    return 0;
}