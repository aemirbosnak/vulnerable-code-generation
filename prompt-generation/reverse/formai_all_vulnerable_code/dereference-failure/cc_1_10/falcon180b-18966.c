//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MIN_VALUE 1
#define MAX_VALUE 100

void generate_matrix(int matrix[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
}

void print_matrix(int matrix[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap_rows(int matrix[SIZE][SIZE], int i, int j) {
    int temp[SIZE];
    for (int k = 0; k < SIZE; k++) {
        temp[k] = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp[k];
    }
}

void swap_cols(int matrix[SIZE][SIZE], int i, int j) {
    for (int k = 0; k < SIZE; k++) {
        int temp = matrix[k][i];
        matrix[k][i] = matrix[k][j];
        matrix[k][j] = temp;
    }
}

int main() {
    int matrix[SIZE][SIZE];
    srand(time(NULL));
    generate_matrix(matrix);
    printf("Original Matrix:\n");
    print_matrix(matrix);

    int row1, col1, row2, col2;
    printf("Enter the coordinates of the first element to swap: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the coordinates of the second element to swap: ");
    scanf("%d %d", &row2, &col2);

    if (col1 == col2) {
        swap_rows(matrix, row1, row2);
    } else {
        swap_cols(matrix, col1, col2);
    }

    printf("Matrix after swapping elements:\n");
    print_matrix(matrix);

    return 0;
}