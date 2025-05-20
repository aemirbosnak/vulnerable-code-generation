//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to generate the Fibonacci sequence using a recursive approach
int fibonacci(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to visualize the Fibonacci sequence using a 2D array
void visualize_fibonacci(int n) {
    // Create a 2D array to store the Fibonacci sequence
    int **sequence = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        sequence[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the first two rows of the 2D array
    sequence[0][0] = 0;
    sequence[1][0] = 1;

    // Calculate the remaining rows of the 2D array
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                sequence[i][j] = sequence[i - 1][n - 1];
            } else {
                sequence[i][j] = sequence[i - 1][j] + sequence[i - 2][j];
            }
        }
    }

    // Print the 2D array to visualize the Fibonacci sequence
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", sequence[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the 2D array
    for (int i = 0; i < n; i++) {
        free(sequence[i]);
    }
    free(sequence);
}

int main() {
    // Get the number of terms in the Fibonacci sequence from the user
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Generate the Fibonacci sequence
    int *sequence = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sequence[i] = fibonacci(i);
    }

    // Visualize the Fibonacci sequence
    visualize_fibonacci(n);

    // Free the memory allocated for the sequence
    free(sequence);

    return 0;
}