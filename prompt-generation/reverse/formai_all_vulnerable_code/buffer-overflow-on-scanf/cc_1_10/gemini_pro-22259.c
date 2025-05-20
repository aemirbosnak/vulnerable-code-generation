//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: random
#include <stdlib.h>
#include <stdio.h>

// Prints the Fibonacci sequence up to the given number of terms
void print_fibonacci(int n) {
    if (n <= 0) {
        printf("Invalid input: n must be a positive integer\n");
        return;
    }

    // Initialize the first two terms of the sequence
    int a = 0, b = 1;

    // Print the first two terms
    printf("%d %d ", a, b);

    // Calculate and print the remaining terms
    for (int i = 2; i < n; i++) {
        int c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    printf("\n");
}

// Visualizes the Fibonacci sequence using ASCII art
void visualize_fibonacci(int n) {
    if (n <= 0) {
        printf("Invalid input: n must be a positive integer\n");
        return;
    }

    // Calculate the maximum width of the numbers in the sequence
    int max_width = 0;
    for (int i = 0; i < n; i++) {
        int num = fibonacci(i);
        int width = snprintf(NULL, 0, "%d", num);
        if (width > max_width) {
            max_width = width;
        }
    }

    // Print the header
    printf("%*s ", max_width, "Index");
    printf("%*s ", max_width, "Value");
    printf("%*s\n", max_width, "Stars");

    // Print the sequence
    for (int i = 0; i < n; i++) {
        int num = fibonacci(i);
        printf("%*d ", max_width, i);
        printf("%*d ", max_width, num);

        // Print the stars
        for (int j = 0; j < num; j++) {
            printf("*");
        }

        printf("\n");
    }
}

// Calculates the nth term of the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Main function
int main() {
    // Get the number of terms from the user
    int n;
    printf("Enter the number of terms to print: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    printf("Fibonacci sequence: ");
    print_fibonacci(n);

    // Visualize the Fibonacci sequence
    printf("\nVisualization of the Fibonacci sequence:\n");
    visualize_fibonacci(n);

    return 0;
}