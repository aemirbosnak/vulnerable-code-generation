//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_fibonacci_sequence(int n) {
    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return;
    }

    long long a = 0, b = 1;
    printf("The Fibonacci Sequence:\n");
    
    // Print the first two Fibonacci numbers
    if (n >= 1) printf("%lld ", a);
    if (n >= 2) printf("%lld ", b);

    // Print the rest of the Fibonacci sequence up to n
    for (int i = 3; i <= n; i++) {
        long long next = a + b;
        printf("%lld ", next);
        a = b;
        b = next;
    }
    printf("\n");
}

void visualize_fibonacci(int n) {
    printf("\nVisualizing Fibonacci Sequence:\n\n");

    long long a = 0, b = 1;

    printf("%-15s | %s\n", "Fib Number", "Width");
    printf("----------------------+----------------\n");

    for (int i = 0; i < n; i++) {
        long long current;
        if (i == 0) {
            current = a;
        } else if (i == 1) {
            current = b;
        } else {
            current = a + b;
            a = b;
            b = current;
        }
        
        // Visual representation
        int width = current > 0 ? current : 1; // Avoid zero width
        printf("%-15lld | ", current);
        
        // Make a visual line based on the Fibonacci number value
        for (int j = 0; j < width / 1000; j++) {
            printf("*");
        }
        printf("\n");
        
        usleep(500000); // Slow down the display for effect
    }
}

int main() {
    int n;
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many Fibonacci numbers would you like to generate? ");
    scanf("%d", &n);

    print_fibonacci_sequence(n);
    visualize_fibonacci(n);

    return 0;
}