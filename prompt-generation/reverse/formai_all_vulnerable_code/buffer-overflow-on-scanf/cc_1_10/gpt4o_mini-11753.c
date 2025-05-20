//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void drawFibonacci(int n) {
    // Initialize the first two Fibonacci numbers
    long long int fib1 = 0, fib2 = 1, next;
    printf("\nFibonacci Sequence Visualization (n = %d):\n", n);
    
    for (int i = 0; i < n; i++) {
        // Print Fibonacci number
        if (i == 0) {
            next = fib1;
        } else if (i == 1) {
            next = fib2;
        } else {
            next = fib1 + fib2;
            fib1 = fib2;
            fib2 = next;
        }
        
        // Determine the scale for visual representation
        int scale = next / 100;
        printf("%lld: ", next);
        
        // Draw the horizontal line representing the Fibonacci number
        for (int j = 0; j < scale; j++) {
            printf("#");
        }
        printf("\n");
        
        // Slow down the printing to visualize the growth
        usleep(500000); // Sleep for 500 milliseconds
    }
}

int main() {
    int n;

    printf("Enter the number of terms to visualize in the Fibonacci sequence: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    drawFibonacci(n);
    
    return 0;
}