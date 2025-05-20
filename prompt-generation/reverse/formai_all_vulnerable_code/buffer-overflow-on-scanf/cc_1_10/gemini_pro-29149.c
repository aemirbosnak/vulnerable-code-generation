//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Macros to check for potential errors
#define CHECK_NULL(ptr) if (ptr == NULL) { fprintf(stderr, "Error: Null pointer detected!\n"); exit(EXIT_FAILURE); }
#define CHECK_CONDITION(condition) if (!(condition)) { fprintf(stderr, "Error: Condition failed!\n"); exit(EXIT_FAILURE); }

// Function to calculate the sum of two numbers
int paranoid_sum(int a, int b) {
    // Check for valid inputs
    CHECK_CONDITION(a >= 0 && b >= 0);

    // Calculate the sum using a loop to avoid integer overflow
    int result = 0;
    for (int i = 0; i < a + b; i++) {
        result++;
    }

    // Check for overflow by comparing the result to the expected value
    long long expected_result = (long long) a + b;
    CHECK_CONDITION(result == expected_result);

    return result;
}

// Function to calculate the product of two numbers
int paranoid_product(int a, int b) {
    // Check for valid inputs
    CHECK_CONDITION(a >= 0 && b >= 0);

    // Calculate the product using a loop to avoid integer overflow
    int result = 0;
    for (int i = 0; i < a * b; i++) {
        result++;
    }

    // Check for overflow by comparing the result to the expected value
    long long expected_result = (long long) a * b;
    CHECK_CONDITION(result == expected_result);

    return result;
}

int main() {
    // Variables to store the inputs
    int a, b;

    // Read the inputs from the user
    printf("Enter two non-negative integers (separated by a space): ");
    scanf("%d %d", &a, &b);

    // Perform the calculations using paranoid functions
    int sum = paranoid_sum(a, b);
    int product = paranoid_product(a, b);

    // Print the results
    printf("The sum of %d and %d is: %d\n", a, b, sum);
    printf("The product of %d and %d is: %d\n", a, b, product);

    return 0;
}