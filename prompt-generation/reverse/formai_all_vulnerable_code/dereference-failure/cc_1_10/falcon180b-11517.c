//Falcon-180B DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_LENGTH 512

// Function to print an error message and exit the program
void error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Function to read a line of input from the user
char* read_line(void) {
    char* line = NULL;
    size_t length = 0;
    ssize_t read;

    line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        error("Out of memory");
    }

    while ((read = getline(&line, &length, stdin))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, length + 1);
            if (line == NULL) {
                error("Out of memory");
            }
        }
    }

    if (ferror(stdin)) {
        error("Error reading input");
    }

    return line;
}

// Function to parse a string as an integer
int parse_int(const char* str) {
    char* end;
    int result = strtol(str, &end, 10);

    if (end == str || *end!= '\0') {
        error("Invalid integer");
    }

    return result;
}

// Function to parse a string as a double
double parse_double(const char* str) {
    char* end;
    double result = strtod(str, &end);

    if (end == str || *end!= '\0') {
        error("Invalid double");
    }

    return result;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main(void) {
    char* line;
    int n;
    double x;
    int result;

    // Read the first line of input as an integer
    line = read_line();
    n = parse_int(line);
    free(line);

    // Read the second line of input as a double
    line = read_line();
    x = parse_double(line);
    free(line);

    // Calculate the factorial of n
    result = factorial(n);

    // Calculate the value of x raised to the power of n
    double value = pow(x, n);

    // Print the results
    printf("Factorial of %d is: %d\n", n, result);
    printf("Value of %g raised to the power of %d is: %g\n", x, n, value);

    return 0;
}