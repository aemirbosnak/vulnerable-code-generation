//Code Llama-13B DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
/*
 * Performance-Critical Component example program in a relaxed style
 *
 * This program demonstrates how to write a performance-critical component in a relaxed style,
 * with a focus on simplicity, readability, and maintainability.
 *
 * The program is a simple calculator that takes in two integers as input, performs a calculation
 * on them, and then outputs the result. The calculation is performed using a relaxed style,
 * which means that the program is designed to be easy to understand and maintain, rather than
 * being optimized for performance.
 *
 * The program is written in a way that makes it easy to understand the logic of the calculation,
 * and the code is organized in a way that makes it easy to maintain and extend. The program
 * uses a modular design, with each function having a clear purpose and being responsible for
 * a specific task.
 *
 * The program is designed to be flexible, with the calculation being performed being easily
 * configurable. The program also includes error handling and validation to ensure that the
 * input is valid and the output is correct.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to perform the calculation
int calculate(int a, int b) {
    return a + b;
}

// Function to validate the input
int validate_input(int a, int b) {
    if (a < 0 || b < 0) {
        printf("Error: Input must be positive integers.\n");
        return 0;
    }
    return 1;
}

// Function to print the output
void print_output(int result) {
    printf("Result: %d\n", result);
}

int main() {
    int a, b, result;

    // Get input from user
    printf("Enter two integers separated by a space: ");
    scanf("%d %d", &a, &b);

    // Validate input
    if (!validate_input(a, b)) {
        return 1;
    }

    // Perform calculation
    result = calculate(a, b);

    // Print output
    print_output(result);

    return 0;
}