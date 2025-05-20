//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TERMS 100

void print_fibonacci(int terms);
void visualize_fibonacci(int* fib, int terms);
void clear_screen();

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer! 🌌\n");
    printf("Enter the number of terms to visualize (1 - %d): ", MAX_TERMS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_TERMS) {
        printf("Please enter a valid number of terms between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    print_fibonacci(n);
    
    return 0;
}

void print_fibonacci(int terms) {
    int fib[MAX_TERMS] = {0};
    fib[0] = 0;
    if (terms > 1) {
        fib[1] = 1;
    }
  
    for (int i = 2; i < terms; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("\nFibonacci Sequence:\n");
    for (int i = 0; i < terms; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
    sleep(1); // Pause for dramatic effect

    visualize_fibonacci(fib, terms);
}

void visualize_fibonacci(int* fib, int terms) {
    clear_screen();
    printf("Visualizing Fibonacci Sequence in a mind-bending way! 🌠\n");
    sleep(1); // Pause for dramatic effect

    for (int i = 0; i < terms; i++) {
        printf("Fibonacci number %d: ", fib[i]);
        for (int j = 0; j < fib[i] + 1; j++) {
            printf("👾");
            usleep(50000); // Create a visual delay
        }
        printf("\n");
        sleep(1); // Pause for dramatic effect
    }
    printf("\nThank you for visualizing with us! 🌈✨\n");
}

void clear_screen() {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}