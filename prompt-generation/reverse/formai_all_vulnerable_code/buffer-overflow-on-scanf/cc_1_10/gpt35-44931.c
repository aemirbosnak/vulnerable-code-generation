//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>

// Function to get the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <=1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to print the first n Fibonacci numbers
void fibonacci_sequence(int n) {
    printf("Fibonacci Sequence:\n");

    // Print the first n Fibonacci numbers
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
}

// Function to print the fibonacci sequence with ascii art
void fibonacci_visualizer(int n) {
    printf("Fibonacci Visualizer:\n");

    // calculate the maximum value of fibonacci sequence
    int max_fibonacci = fibonacci(n);

    // set the starting points of the fibonacci sequence
    int a = 0;
    int b = 1;

    // Iterate through the Fibonacci sequence up to the nth term
    for (int i = 0; i < n; i++) {
        int current_fibonacci = fibonacci(i);

        // Iterate through each number up to the current Fibonacci value
        for (int j = a; j < current_fibonacci; j++) {
            // Print a space if b is less than the max Fibonacci value
            if (b < max_fibonacci) {
                printf(" ");
            }
            // Print an asterisk if b is equal to the current Fibonacci value
            else {
                printf("*");
            }

            b++;
        }

        // Update the starting values for the next Fibonacci value
        a = current_fibonacci;
        b = 1;

        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);

    fibonacci_sequence(n);
    fibonacci_visualizer(n);

    return 0;
}