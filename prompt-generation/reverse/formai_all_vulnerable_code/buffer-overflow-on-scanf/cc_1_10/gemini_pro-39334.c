//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print the Fibonacci sequence up to the nth term
void print_fibonacci_sequence(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to visualize the Fibonacci sequence using ASCII art
void visualize_fibonacci_sequence(int n) {
    for (int i = 0; i < n; i++) {
        // Calculate the number of asterisks to print for the ith term
        int num_asterisks = fibonacci(i);

        // Print the asterisks
        for (int j = 0; j < num_asterisks; j++) {
            printf("*");
        }

        // Print a newline character
        printf("\n");
    }
}

// Main function
int main() {
    // Get the number of terms from the user
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    printf("The Fibonacci sequence up to the %dth term is: ", n);
    print_fibonacci_sequence(n);

    // Visualize the Fibonacci sequence
    printf("\nVisualization of the Fibonacci sequence:\n");
    visualize_fibonacci_sequence(n);

    return 0;
}