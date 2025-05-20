//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store calculator operations
typedef struct Calculator {
    char operator;
    double operand1;
    double operand2;
    double result;
} Calculator;

// Function to perform calculator operations
double calculate(Calculator *calc) {
    switch (calc->operator) {
        case '+':
            calc->result = calc->operand1 + calc->operand2;
            break;
        case '-':
            calc->result = calc->operand1 - calc->operand2;
            break;
        case '*':
            calc->result = calc->operand1 * calc->operand2;
            break;
        case '/':
            if (calc->operand2 == 0) {
                printf("Error: division by zero is not allowed");
                return -1;
            }
            calc->result = calc->operand1 / calc->operand2;
            break;
    }

    return calc->result;
}

int main() {
    Calculator calc;

    // Get operator, operand1, and operand2 from the user
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &calc.operator);

    printf("Enter operand 1: ");
    scanf("%lf", &calc.operand1);

    printf("Enter operand 2: ");
    scanf("%lf", &calc.operand2);

    // Perform calculator operation
    double result = calculate(&calc);

    // Display the result
    if (result != -1) {
        printf("The result is: %.2lf", result);
    }

    return 0;
}