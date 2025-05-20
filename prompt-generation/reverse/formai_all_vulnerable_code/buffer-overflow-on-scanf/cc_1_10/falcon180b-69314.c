//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random double between min and max (inclusive)
double rand_double(double min, double max) {
    return (double)rand() / RAND_MAX * (max - min) + min;
}

int main() {
    int i, j, rows, cols;

    // Get user input for the size of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Create the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Fill the matrix with random numbers
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand_int(1, 100);
        }
    }

    // Print the matrix
    printf("Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate the sum of all elements in the matrix
    int sum = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    printf("\nSum of all elements in the matrix: %d\n", sum);

    // Calculate the average of all elements in the matrix
    double avg = (double)sum / rows / cols;
    printf("Average of all elements in the matrix: %.2f\n", avg);

    // Free the memory allocated for the matrix
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}