//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Function prototypes
float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);
float power(float num, int pow);

// Recursive function to evaluate the expression
float evaluateExpression(char operator, float num1, float num2) {
    float result;
    switch(operator) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        case '^':
            result = power(num1, (int)num2);
            break;
    }
    return result;
}

// Function to get the input from the user
void getInput(float *operand1, float *operand2, char *operator) {
    printf("Enter the expression: ");
    scanf("%f%c%f", operand1, operator, operand2);
}

int main() {
    float operand1, operand2, result;
    char operator;
    getInput(&operand1, &operand2, &operator);
    result = evaluateExpression(operator, operand1, operand2);
    printf("%.2f %c %.2f = %.2f", operand1, operator, operand2, result);
    return 0;
}

// Function to add two numbers recursively
float add(float num1, float num2) {
    return (num2 == 0) ? num1 : add(num1 + 1, num2 - 1);
}

// Function to subtract two numbers recursively
float subtract(float num1, float num2) {
    return (num2 == 0) ? num1 : subtract(num1 - 1, num2 - 1);
}

// Function to multiply two numbers recursively
float multiply(float num1, float num2) {
    return (num2 == 1) ? num1 : add(multiply(num1, num2 - 1), num1);
}

// Function to divide two numbers recursively
float divide(float num1, float num2) {
    return (num2 == 1) ? num1 : subtract(divide(num1, num2 - 1), num1/num2 - 1);
}

// Function to calculate power of a number recursively
float power(float num, int pow) {
    return (pow == 0) ? 1 : multiply(num, power(num, pow - 1));
}