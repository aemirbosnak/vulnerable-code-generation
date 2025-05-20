//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB 20
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

void print_fibonacci_visual(int n) {
    if (n <= 0) {
        printf("Invalid input for Fibonacci visualization.\n");
        return;
    }

    long long fib1 = 0, fib2 = 1, fib_next;
    
    printf(COLOR_GREEN "Fibonacci Sequence Visualization (up to first %d terms):\n" COLOR_RESET, n);
    
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            fib_next = fib1; // Fibonacci(1) = 0
        } else if (i == 2) {
            fib_next = fib2; // Fibonacci(2) = 1
        } else {
            fib_next = fib1 + fib2; // Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
            fib1 = fib2;
            fib2 = fib_next;
        }
        
        printf("%2d: ", i);
        if (fib_next > 0) {
            for (long long j = 0; j < fib_next; j++) {
                printf("*");
            }
        }
        printf(" (%lld)\n", fib_next);
    }
}

int main() {
    int n;

    printf(COLOR_YELLOW "Enter how many terms of the Fibonacci sequence to visualize (1-%d): " COLOR_RESET, MAX_FIB);
    scanf("%d", &n);

    if (n < 1 || n > MAX_FIB) {
        printf(COLOR_RED "Error: Please enter a number between 1 and %d.\n" COLOR_RESET, MAX_FIB);
        return EXIT_FAILURE;
    }

    print_fibonacci_visual(n);

    return EXIT_SUCCESS;
}