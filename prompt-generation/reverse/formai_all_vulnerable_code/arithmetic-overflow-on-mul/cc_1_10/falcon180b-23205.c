//Falcon-180B DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_LENGTH 256

// Function to print the error message
void print_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Function to check if the input string is a valid integer
bool is_valid_int(const char* str) {
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

// Main function to read the input number and calculate its factorial
int main() {
    char input[MAX_LINE_LENGTH];
    printf("Enter a positive integer: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = '\0';

    // Check if the input string is a valid integer
    if (!is_valid_int(input)) {
        print_error("Invalid input. Please enter a positive integer.");
    }

    // Convert the input string to an integer
    int n = atoi(input);

    // Check if the input number is negative
    if (n < 0) {
        print_error("Invalid input. Please enter a positive integer.");
    }

    // Calculate the factorial of the input number
    int result = factorial(n);

    // Print the result
    printf("The factorial of %d is %d\n", n, result);

    return EXIT_SUCCESS;
}