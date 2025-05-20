//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci sequence
void fibonacci(int n) {
    int first = 0, second = 1, next;
    int i;
    printf("%d %d ", first, second); // Print first two numbers
    
    // Generating Fibonacci sequence
    for (i = 2; i < n; i++) {
        next = first + second;
        first = second;
        second = next;
        printf("%d ", next); // Print generated number
    }
}

// Function to print Fibonacci sequence as a pattern
void fibonacciPattern(int n) {
    int first = 0, second = 1, next;
    int i, j, count = 0;
    
    // Creating a 2D array to store pattern
    int pattern[n][n];

    // Generating Fibonacci sequence and storing in pattern array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            next = first + second;
            first = second;
            second = next;
            pattern[i][j] = next;
        }
    }

    // Printing pattern array as visualizer
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", pattern[i][j]);
        }
        count++;
        printf("\t");
        if (count == 2) {
            printf("\n");
            count = 0;
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    // Validating user input
    if (n < 2) {
        printf("Please enter a valid number (minimum 2)\n");
        exit(0); // Exiting program if input is invalid
    }

    // Generating Fibonacci sequence
    printf("Fibonacci sequence: ");
    fibonacci(n);

    printf("\n\n");

    // Printing Fibonacci sequence as pattern
    printf("Fibonacci pattern:\n");
    fibonacciPattern(n);

    printf("\n\n");

    printf("It's always exciting to visualize Fibonacci sequence!\n");

    return 0;
}