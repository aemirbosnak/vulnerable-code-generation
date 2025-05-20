//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number
unsigned long long fibonacci(unsigned int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to generate the ASCII art representation of the nth Fibonacci number
char *fibonacci_art(unsigned int n) {
    // Calculate the Fibonacci number
    unsigned long long fib = fibonacci(n);

    // Convert the Fibonacci number to a string
    char *fib_str = malloc(20);
    sprintf(fib_str, "%llu", fib);

    // Generate the ASCII art representation
    char *art = malloc(100);
    int i, j, k;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            k = i * 10 + j;
            if (k < n) {
                art[k] = ' ';
            } else if (k == n) {
                art[k] = '*';
            } else {
                art[k] = fib_str[k - n - 1];
            }
        }
    }

    // Null-terminate the string
    art[100] = '\0';

    // Return the ASCII art representation
    return art;
}

// Function to print the ASCII art representation of the nth Fibonacci number
void print_fibonacci_art(unsigned int n) {
    // Generate the ASCII art representation
    char *art = fibonacci_art(n);

    // Print the ASCII art representation
    printf("%s\n", art);

    // Free the memory allocated for the ASCII art representation
    free(art);
}

// Main function
int main() {
    // Get the number of Fibonacci numbers to generate
    unsigned int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%u", &n);

    // Generate and print the ASCII art representation of each Fibonacci number
    for (unsigned int i = 0; i < n; i++) {
        print_fibonacci_art(i);
    }

    return 0;
}