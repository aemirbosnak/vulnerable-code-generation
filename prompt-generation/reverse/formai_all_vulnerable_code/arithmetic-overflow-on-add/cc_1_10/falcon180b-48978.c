//Falcon-180B DATASET v1.0 Category: Error handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define error codes
#define ERR_SUCCESS 0
#define ERR_INVALID_INPUT 1
#define ERR_INVALID_OPERATION 2
#define ERR_MEMORY_ALLOCATION_FAILED 3

// Function prototypes
int input_integer(const char* prompt);
int calculate_sum(int num1, int num2);
void print_error(int error_code);

// Main function
int main() {
    int num1, num2, result;

    // Get input from user
    num1 = input_integer("Enter the first integer: ");
    num2 = input_integer("Enter the second integer: ");

    // Calculate sum
    result = calculate_sum(num1, num2);

    // Print result
    printf("The sum of %d and %d is %d.\n", num1, num2, result);

    return ERR_SUCCESS;
}

// Function to get integer input from user
int input_integer(const char* prompt) {
    char input[20];
    int value;

    // Prompt user for input
    printf("%s: ", prompt);
    fgets(input, sizeof(input), stdin);

    // Convert input to integer
    value = atoi(input);

    // Check for invalid input
    if (value == 0 && input[0]!= '0') {
        print_error(ERR_INVALID_INPUT);
        exit(ERR_INVALID_INPUT);
    }

    return value;
}

// Function to calculate sum of two integers
int calculate_sum(int num1, int num2) {
    int result = num1 + num2;

    // Check for integer overflow
    if (result < num1 || result < num2) {
        print_error(ERR_INVALID_OPERATION);
        exit(ERR_INVALID_OPERATION);
    }

    return result;
}

// Function to print error message and exit program
void print_error(int error_code) {
    switch (error_code) {
        case ERR_INVALID_INPUT:
            printf("Invalid input.\n");
            break;
        case ERR_INVALID_OPERATION:
            printf("Invalid operation.\n");
            break;
        case ERR_MEMORY_ALLOCATION_FAILED:
            printf("Memory allocation failed.\n");
            break;
        default:
            printf("Unknown error.\n");
            break;
    }

    exit(error_code);
}