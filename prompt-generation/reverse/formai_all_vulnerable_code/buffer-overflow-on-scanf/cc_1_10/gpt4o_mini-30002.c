//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 20

void draw_fibonacci(int term, int prev1, int prev2) {
    // This function will create a visual representation of the Fibonacci sequence.
    for (int i = 0; i < term; i++) {
        if (i == 0) {
            printf("  %d", prev1);
        } else if (i == 1) {
            printf("  %d", prev2);
        } else {
            int next = prev1 + prev2;
            printf("  %d", next);
            prev1 = prev2;
            prev2 = next;
        }
    }
    printf("\n");
}

void print_fibonacci_sequence(int n) {
    // Function to print Fibonacci terms
    printf("First %d terms of the Fibonacci sequence:\n", n);
    int prev1 = 0, prev2 = 1;

    draw_fibonacci(n, prev1, prev2);
}

void draw_graph(int fib[], int n) {
    // Function to draw a simple graph for Fibonacci sequence
    printf("\nVisual Representation of Fibonacci Sequence:\n");
    int max_value = fib[n-1];

    for (int i = 0; i < n; i++) {
        int height = (fib[i] * 20) / max_value; // Adjust the height relative to max
        printf("%3d | ", fib[i]);
        for (int j = 0; j < height; j++) {
            printf("#");
        }
        printf("\n");
    }
    printf("    +");
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n    ");
    for (int i = 0; i < n; i++) {
        printf("%2d ", i);
    }
    printf("\n");
}

int main() {
    int fibonacci[MAX_TERMS];
    fibonacci[0] = 0; // F(0)
    fibonacci[1] = 1; // F(1)

    printf("Welcome to the Fibonacci Sequence Visualizer!\n\n");

    int terms = 0;
    while (1) {
        printf("Enter the number of Fibonacci terms you want to visualize (1-%d): ", MAX_TERMS);
        scanf("%d", &terms);

        if (terms >= 1 && terms <= MAX_TERMS) {
            break;
        } else {
            printf("Please enter a valid number within the specified range.\n");
        }
    }

    // Calculate Fibonacci and store in the array
    for (int i = 2; i < terms; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // Print the Fibonacci sequence
    print_fibonacci_sequence(terms);

    // Draw a graph for the Fibonacci sequence
    draw_graph(fibonacci, terms);

    printf("\nThank you for using the Fibonacci Sequence Visualizer! Goodbye!\n");
    return 0;
}