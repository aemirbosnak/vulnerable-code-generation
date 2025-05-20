//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error handling
void error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

// Recursive function to find the nth Fibonacci number
unsigned long long fibonacci(unsigned int n) {
    // Base cases
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Custom input validation
unsigned int get_positive_integer(const char *prompt) {
    char input[100];
    unsigned int value;

    while (1) {
        printf("%s: ", prompt);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            error("Invalid input");
        }

        if (sscanf(input, "%u", &value) != 1) {
            error("Invalid input");
        }

        if (value > 0) {
            return value;
        } else {
            error("Please enter a positive integer");
        }
    }
}

int main() {
    unsigned int n;

    // Get the input from the user
    n = get_positive_integer("Enter the nth Fibonacci number you want to find");

    // Calculate the nth Fibonacci number using recursion
    unsigned long long fib = fibonacci(n);

    // Print the result
    printf("The %u-th Fibonacci number is %llu\n", n, fib);

    return EXIT_SUCCESS;
}