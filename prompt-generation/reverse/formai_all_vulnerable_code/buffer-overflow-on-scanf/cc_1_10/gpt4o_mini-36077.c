//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for usleep function
#include <string.h>

// Function to print a colorful representation of the Fibonacci sequence
void print_fibonacci(int n) {
    int fib1 = 0, fib2 = 1, next_fib;
    
    printf("\n✨✨✨ Welcome to the Fibonacci Sequence Visualizer! ✨✨✨\n");
    printf("Here's how the Fibonacci numbers blossom:\n\n");

    // Colors for terminal output
    const char *colors[] = { "\033[0;31m", "\033[0;32m", "\033[0;33m", "\033[0;34m", "\033[0;35m", "\033[0;36m", "\033[0;37m", "\033[0;0m" };
    
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next_fib = i; // The first two Fibonacci numbers
        } else {
            next_fib = fib1 + fib2; // Fibonacci sequence calculation
            fib1 = fib2; // Update the previous number
            fib2 = next_fib; // Update the current number
        }

        // Choose a color for this Fibonacci number
        const char *color = colors[i % (sizeof(colors) / sizeof(colors[0]) - 1)];
        
        // Print the Fibonacci number
        printf("%sFibonacci #%d: %d%s\n", color, i, next_fib, colors[7]);
        
        // Sleep for a moment to create a pause
        usleep(500000); // 500ms
    }

    printf("\n🌟 Thanks for visualizing the Fibonacci sequence with us! 🌟\n");
}

int main() {
    int n;

    // Welcome message
    printf("🎉🎉🎉 Hi there! Let's visualize the Fibonacci sequence! 🎉🎉🎉\n");
    printf("How many terms would you like to see? (Enter a positive integer): ");
    
    // Loop until a valid number is entered
    while (1) {
        scanf("%d", &n);
        if (n > 0) {
            break;
        } else {
            printf("Oops! Please enter a positive integer greater than zero: ");
        }
    }
    
    // Invoke the Fibonacci printer function
    print_fibonacci(n);
    
    return 0;
}