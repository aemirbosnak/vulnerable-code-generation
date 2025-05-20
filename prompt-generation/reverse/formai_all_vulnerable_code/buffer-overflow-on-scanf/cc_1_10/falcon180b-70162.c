//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random integer matrix of size rows x cols
int **create_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand_num(1, 100);
        }
    }
    return matrix;
}

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the sum of all elements in a matrix
int sum_matrix(int **matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Function to calculate the average of all elements in a matrix
double avg_matrix(int **matrix, int rows, int cols) {
    int sum = sum_matrix(matrix, rows, cols);
    double avg = (double)sum / (rows * cols);
    return avg;
}

int main() {
    srand(time(NULL));
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int **matrix = create_matrix(rows, cols);
    printf("Random matrix:\n");
    print_matrix(matrix, rows, cols);
    int sum = sum_matrix(matrix, rows, cols);
    printf("Sum of all elements: %d\n", sum);
    double avg = avg_matrix(matrix, rows, cols);
    printf("Average of all elements: %.2f\n", avg);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}