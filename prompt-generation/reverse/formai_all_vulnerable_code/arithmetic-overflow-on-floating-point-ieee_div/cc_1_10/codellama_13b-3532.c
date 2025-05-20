//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define MAX_OPERATIONS 10
#define MAX_INPUT_SIZE 100

// Define structure for storing input values
typedef struct {
    char operation[MAX_OPERATIONS];
    double value1;
    double value2;
} input_t;

// Define function for calculating the result of an operation
double calculate_result(char operation, double value1, double value2) {
    switch (operation) {
        case '+':
            return value1 + value2;
        case '-':
            return value1 - value2;
        case '*':
            return value1 * value2;
        case '/':
            return value1 / value2;
        default:
            return 0.0;
    }
}

// Define function for reading input from the user
void read_input(input_t *input) {
    // Read operation
    printf("Enter operation (+, -, *, /): ");
    scanf("%c", &input->operation);

    // Read values
    printf("Enter value 1: ");
    scanf("%lf", &input->value1);
    printf("Enter value 2: ");
    scanf("%lf", &input->value2);
}

// Define function for printing the result
void print_result(double result) {
    printf("Result: %f\n", result);
}

int main() {
    // Initialize input structure
    input_t input;

    // Read input from the user
    read_input(&input);

    // Calculate result
    double result = calculate_result(input.operation, input.value1, input.value2);

    // Print result
    print_result(result);

    return 0;
}