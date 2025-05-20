//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to hold arithmetic operations
typedef struct {
    char operator;
    double operand1;
    double operand2;
} ArithmeticOperation;

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return a / b;
}

// Function to perform square root
double sqrt(double a) {
    return sqrt(a);
}

// Function to perform power
double power(double a, double b) {
    return pow(a, b);
}

// Function to evaluate an arithmetic expression
double evaluateExpression(ArithmeticOperation* operation) {
    double result = 0;
    switch (operation->operator) {
        case '+':
            result = add(operation->operand1, operation->operand2);
            break;
        case '-':
            result = subtract(operation->operand1, operation->operand2);
            break;
        case '*':
            result = multiply(operation->operand1, operation->operand2);
            break;
        case '/':
            result = divide(operation->operand1, operation->operand2);
            break;
        case '^':
            result = power(operation->operand1, operation->operand2);
            break;
        case's':
            result = sqrt(operation->operand1);
            break;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
    return result;
}

// Function to parse an arithmetic expression
ArithmeticOperation* parseExpression(char* expression) {
    ArithmeticOperation* operation = (ArithmeticOperation*)malloc(sizeof(ArithmeticOperation));
    char* token = strtok(expression, " ");
    operation->operator = token[0];
    operation->operand1 = atof(strtok(NULL, " "));
    operation->operand2 = atof(strtok(NULL, " "));
    return operation;
}

// Function to print the result of an arithmetic expression
void printResult(double result) {
    printf("Result: %.2f\n", result);
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expression);
    ArithmeticOperation* operation = parseExpression(expression);
    double result = evaluateExpression(operation);
    printResult(result);
    return 0;
}