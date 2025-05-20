//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_VAL 1000

// Function to initialize a matrix with random values
void initialize_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int min_val, int max_val) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (max_val - min_val + 1) + min_val;
        }
    }
}

// Function to print the matrix
void print_matrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the maximum sum of a contiguous subarray
int max_sum_subarray(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int max_sum = INT_MIN;
    int curr_sum = 0;
    int start_row = 0;
    int end_row = 0;

    for (int i = 0; i < rows; i++) {
        curr_sum = 0;
        for (int j = 0; j < cols; j++) {
            curr_sum += matrix[i][j];
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                start_row = i;
                end_row = i;
            }
        }
    }

    return max_sum;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[MAX_ROWS][MAX_COLS];
    initialize_matrix(matrix, rows, cols, 0, 100);

    print_matrix(matrix, rows, cols);

    int max_sum = max_sum_subarray(matrix, rows, cols);

    printf("Maximum sum of a contiguous subarray: %d\n", max_sum);

    return 0;
}