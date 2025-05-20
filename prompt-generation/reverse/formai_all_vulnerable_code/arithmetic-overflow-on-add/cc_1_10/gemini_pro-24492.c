//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 10
#define MIN_Y -5
#define MAX_Y 5
#define MIN_X -4
#define MAX_X 4

typedef struct {
    int y;
    int x;
    int value;
} number_t;

// Function to print the Fibonacci sequence in a matrix
void print_fibonacci_matrix(number_t matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    // Print the matrix
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%3d ", matrix[i][j].value);
        }
        printf("\n");
    }
}

// Function to generate the Fibonacci sequence
void generate_fibonacci_sequence(number_t matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    // Initialize the first two numbers in the sequence
    matrix[0][0].y = 0;
    matrix[0][0].x = 0;
    matrix[0][0].value = 0;
    matrix[1][0].y = 1;
    matrix[1][0].x = 0;
    matrix[1][0].value = 1;

    // Generate the rest of the sequence
    for (int i = 2; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            // Calculate the next number in the sequence
            matrix[i][j].value = matrix[i - 1][j].value + matrix[i - 2][j].value;
            // Calculate the y and x coordinates of the number
            matrix[i][j].y = matrix[i - 1][j].y + matrix[i - 2][j].y;
            matrix[i][j].x = matrix[i - 1][j].x + matrix[i - 2][j].x;
        }
    }
}

// Function to visualize the Fibonacci sequence
void visualize_fibonacci_sequence(number_t matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    // Create a new matrix to store the visualized Fibonacci sequence
    int visualized_matrix[MAX_Y - MIN_Y + 1][MAX_X - MIN_X + 1];

    // Initialize the visualized matrix to 0
    for (int i = MIN_Y; i <= MAX_Y; i++) {
        for (int j = MIN_X; j <= MAX_X; j++) {
            visualized_matrix[i - MIN_Y][j - MIN_X] = 0;
        }
    }

    // Visualize the Fibonacci sequence
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j].y >= MIN_Y && matrix[i][j].y <= MAX_Y && matrix[i][j].x >= MIN_X && matrix[i][j].x <= MAX_X) {
                visualized_matrix[matrix[i][j].y - MIN_Y][matrix[i][j].x - MIN_X] = matrix[i][j].value;
            }
        }
    }

    // Print the visualized matrix
    for (int i = MAX_Y; i >= MIN_Y; i--) {
        for (int j = MIN_X; j <= MAX_X; j++) {
            printf("%3d ", visualized_matrix[i - MIN_Y][j - MIN_X]);
        }
        printf("\n");
    }
}

int main() {
    // Create a matrix to store the Fibonacci sequence
    number_t matrix[MATRIX_SIZE][MATRIX_SIZE];

    // Generate the Fibonacci sequence
    generate_fibonacci_sequence(matrix);

    // Print the Fibonacci sequence
    print_fibonacci_matrix(matrix);

    // Visualize the Fibonacci sequence
    visualize_fibonacci_sequence(matrix);

    return 0;
}