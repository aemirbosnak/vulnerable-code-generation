//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void print_fibonacci(int n) {
    long long int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    printf("Fibonacci Sequence:\n");
    for(int i = 0; i < n; i++) {
        if (i > 1) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        printf("%lld ", fib[i]);
    }
    printf("\n\n");
}

void visualize_fibonacci(int n) {
    long long int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 0; i < n; i++) {
        if (i > 1) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        
        // Generate the visual representation with asterisks
        printf("Fibonacci number %d: ", i);
        for (long long int j = 0; j < fib[i]; j += 100000) { // scaling down for visualization
            printf("*");
        }
        printf(" (Value: %lld)\n", fib[i]);
    }
}

int main() {
    int count;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Let's explore the Fibonacci numbers.\n");
    
    printf("How many Fibonacci numbers would you like to see? ");
    scanf("%d", &count);

    // Make sure the number is a positive integer
    if (count < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    print_fibonacci(count);
    visualize_fibonacci(count);
    
    printf("Thank you for using the Fibonacci Sequence Visualizer!\n");
    printf("Keep exploring the wonders of mathematics!\n");

    return 0;
}