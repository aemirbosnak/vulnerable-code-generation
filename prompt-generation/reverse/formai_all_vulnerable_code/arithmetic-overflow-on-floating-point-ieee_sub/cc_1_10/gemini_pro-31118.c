//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Constants */
#define MAX_INPUT_LENGTH 256
#define MAX_OPERANDS 10
#define MAX_OPERATORS 10

/* Function prototypes */
double evaluate(char *expression);
int get_operands(char *expression, double *operands);
int get_operators(char *expression, char *operators);
int is_operand(char c);
int is_operator(char c);
double apply_operator(char operator, double operand1, double operand2);

/* Main function */
int main() {
    char input[MAX_INPUT_LENGTH];
    double result;

    printf("Enter an expression to evaluate: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    result = evaluate(input);

    printf("Result: %f\n", result);

    return 0;
}

/* Function to evaluate an expression */
double evaluate(char *expression) {
    double operands[MAX_OPERANDS];
    char operators[MAX_OPERATORS];
    int num_operands, num_operators;
    int i;

    /* Get the operands and operators from the expression */
    num_operands = get_operands(expression, operands);
    num_operators = get_operators(expression, operators);

    /* Evaluate the expression */
    for (i = 0; i < num_operators; i++) {
        operands[i + 1] = apply_operator(operators[i], operands[i], operands[i + 1]);
    }

    /* Return the result */
    return operands[num_operands];
}

/* Function to get the operands from an expression */
int get_operands(char *expression, double *operands) {
    int i, j;
    char operand[MAX_INPUT_LENGTH];

    i = 0;
    j = 0;
    while (expression[i] != '\0') {
        if (is_operand(expression[i])) {
            operand[j] = expression[i];
            j++;
        } else if (expression[i] == ' ') {
            operand[j] = '\0';
            operands[i] = atof(operand);
            j = 0;
        }
        i++;
    }

    /* Return the number of operands */
    return i;
}

/* Function to get the operators from an expression */
int get_operators(char *expression, char *operators) {
    int i, j;

    i = 0;
    j = 0;
    while (expression[i] != '\0') {
        if (is_operator(expression[i])) {
            operators[j] = expression[i];
            j++;
        }
        i++;
    }

    /* Return the number of operators */
    return j;
}

/* Function to check if a character is an operand */
int is_operand(char c) {
    return c >= '0' && c <= '9';
}

/* Function to check if a character is an operator */
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/* Function to apply an operator to two operands */
double apply_operator(char operator, double operand1, double operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                fprintf(stderr, "Error: Division by zero.\n");
                exit(1);
            }
            return operand1 / operand2;
        default:
            fprintf(stderr, "Error: Invalid operator '%c'.\n", operator);
            exit(1);
    }
}