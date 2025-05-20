//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_fibonacci_sequence(int n);
void display_visualization(int fib, int index);

int main() {
    int n;

    printf("🌟 Welcome to the Fibonacci Sequence Visualizer! 🌟\n");
    printf("How many Fibonacci numbers would you like to see? (Enter a positive integer): ");

    while (1) {
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("🚫 Oops! Please enter a valid positive integer: ");
            while(getchar() != '\n'); // clear the input buffer
        } else {
            break;
        }
    }

    printf("\n🎉 Generating Fibonacci sequence...\n\n");
    print_fibonacci_sequence(n);
    printf("\n✨ Thanks for using the Fibonacci Sequence Visualizer! Goodbye! ✨\n");

    return 0;
}

void print_fibonacci_sequence(int n) {
    int fib1 = 0, fib2 = 1, next_fib;

    // Print the first two Fibonacci numbers, 0 and 1
    display_visualization(fib1, 0);
    if (n > 1) {
        display_visualization(fib2, 1);
    }

    // Generate and display the next Fibonacci numbers
    for (int i = 2; i < n; i++) {
        next_fib = fib1 + fib2;
        display_visualization(next_fib, i);
        fib1 = fib2;
        fib2 = next_fib;
    }
}

void display_visualization(int fib, int index) {
    // Create a colorful effect for the output
    printf("F(%d) = \x1b[32m%d\x1b[0m\n", index, fib);

    // Simple visualization using asterisks
    printf("Visualization: ");
    for (int i = 0; i < fib; i++) {
        printf("*");
        fflush(stdout);
        usleep(50000); // wait for 50 milliseconds for a cheerful effect
    }
    printf("\n\n");
}