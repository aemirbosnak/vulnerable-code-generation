//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>
#include <stdlib.h>

void draw_fibonacci_visual(int term, int fib_value) {
    printf("\nFibonacci(%d) = %d\n", term, fib_value);
    for (int i = 0; i < fib_value; i++) {
        printf("*");
    }
    printf("\n");
}

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    
    return b;
}

void visualize_fibonacci_sequence(int terms) {
    printf("Visualizing Fibonacci Sequence:\n");
    printf("Number of Terms: %d\n", terms);

    for (int i = 0; i < terms; i++) {
        int fib_value = fibonacci(i);
        draw_fibonacci_visual(i, fib_value);
    }
}

int main() {
    int terms = 0;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms of the Fibonacci sequence would you like to see? ");
    
    if (scanf("%d", &terms) != 1 || terms < 1) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    visualize_fibonacci_sequence(terms);

    return 0;
}