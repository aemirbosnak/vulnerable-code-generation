//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TERMS 50000

// Function to generate the Fibonacci sequence
void generate_fibonacci_sequence(int n) {
    int fib_sequence[MAX_TERMS];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2];
    }

    // Print the sequence
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib_sequence[i]);
    }
    printf("\n");
}

// Function to visualize the Fibonacci sequence using ASCII art
void visualize_fibonacci_sequence(int n) {
    int fib_sequence[MAX_TERMS];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2];
    }

    int max_width = 0;
    // Calculate the maximum width of each term in the sequence
    for (int i = 0; i < n; i++) {
        int term_width = (int)log10(fib_sequence[i]) + 1;
        if (term_width > max_width) {
            max_width = term_width;
        }
    }

    // Print the sequence with ASCII art
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        int term_width = (int)log10(fib_sequence[i]) + 1;
        for (int j = 0; j < max_width - term_width; j++) {
            printf(" ");
        }
        printf("%d", fib_sequence[i]);
        for (int j = 0; j < max_width - term_width; j++) {
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Generate and print the Fibonacci sequence
    generate_fibonacci_sequence(n);

    // Visualize the Fibonacci sequence
    visualize_fibonacci_sequence(n);

    return 0;
}