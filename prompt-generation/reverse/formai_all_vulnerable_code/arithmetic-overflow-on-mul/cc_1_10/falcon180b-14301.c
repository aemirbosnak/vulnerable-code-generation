//Falcon-180B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

// Define maximum input size
#define MAX_SIZE 100

// Function to check if input is a valid integer
bool is_integer(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    char input[MAX_SIZE];
    int n;

    // Prompt user for input
    printf("Enter a non-negative integer: ");

    // Read input
    if (fgets(input, MAX_SIZE, stdin) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    // Remove newline character from input
    if (input[strcspn(input, "\n")]!= '\0') {
        fprintf(stderr, "Input too long.\n");
        exit(EXIT_FAILURE);
    }

    // Convert input to integer
    n = atoi(input);

    // Check if input is a non-negative integer
    if (n < 0) {
        fprintf(stderr, "Input must be non-negative.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate factorial
    int result = factorial(n);

    // Print result
    printf("The factorial of %d is %d.\n", n, result);

    return 0;
}