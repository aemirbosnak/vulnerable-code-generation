//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
// Scientific Calculator Implementation
#include <stdio.h>
#include <math.h>

// Define the functions
void calculate(double, double, char, double*);
void print_result(double);

int main() {
    double num1, num2, result;
    char op;

    // Get the input from the user
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &op);

    // Calculate the result
    calculate(num1, num2, op, &result);

    // Print the result
    print_result(result);

    return 0;
}

// Calculate the result
void calculate(double num1, double num2, char op, double* result) {
    switch (op) {
        case '+':
            *result = num1 + num2;
            break;
        case '-':
            *result = num1 - num2;
            break;
        case '*':
            *result = num1 * num2;
            break;
        case '/':
            *result = num1 / num2;
            break;
        default:
            printf("Invalid operator\n");
            break;
    }
}

// Print the result
void print_result(double result) {
    printf("The result is: %f\n", result);
}