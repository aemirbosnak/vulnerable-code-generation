//Falcon-180B DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid integer
bool isInteger(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to calculate the factorial of a given number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to handle errors and print error messages
void handleError(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

int main() {
    int n;
    char input[100];

    // Prompt user to enter a positive integer
    printf("Enter a positive integer: ");
    fgets(input, 100, stdin);

    // Check if input is a valid integer
    if (!isInteger(input)) {
        handleError("Invalid input. Please enter a positive integer.");
    }

    // Convert input to integer
    n = atoi(input);

    // Check if input is positive
    if (n <= 0) {
        handleError("Invalid input. Please enter a positive integer.");
    }

    // Calculate factorial of input
    int result = factorial(n);

    // Print result
    printf("The factorial of %d is %d\n", n, result);

    return 0;
}