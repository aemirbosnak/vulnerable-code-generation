//Falcon-180B DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Function to print error message and exit program
void error_message(const char* format,...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    exit(1);
}

// Function to read integer input from user
int read_int(const char* prompt) {
    int result;
    printf("%s", prompt);
    if (scanf("%d", &result)!= 1) {
        error_message("Invalid input: %s\n", prompt);
    }
    return result;
}

// Function to read floating-point input from user
double read_double(const char* prompt) {
    double result;
    printf("%s", prompt);
    if (scanf("%lf", &result)!= 1) {
        error_message("Invalid input: %s\n", prompt);
    }
    return result;
}

// Function to calculate factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Main function
int main() {
    int n, result;
    double pi;

    // Read input from user
    n = read_int("Enter a number: ");
    pi = read_double("Enter the value of pi: ");

    // Calculate factorial and result
    result = factorial(n) * pi;

    // Print result
    printf("The result is: %d\n", result);

    return 0;
}