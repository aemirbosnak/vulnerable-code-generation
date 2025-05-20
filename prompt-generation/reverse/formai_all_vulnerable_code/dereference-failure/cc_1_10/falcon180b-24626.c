//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

// Function to check if a character is a valid operand
int is_operand(char c) {
    return (c >= '0' && c <= '9') || (c == '.') || (c == '-');
}

// Function to check if a character is a valid operator
int is_operator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

// Function to evaluate an expression
double evaluate_expression(char *expression) {
    double result = 0;
    char *token = strtok(expression, " ");
    while (token!= NULL) {
        if (is_operand(token[0])) {
            result += atof(token);
        } else {
            double operand1 = result;
            double operand2 = atof(token);
            double temp_result;
            switch (token[0]) {
                case '+':
                    temp_result = operand1 + operand2;
                    break;
                case '-':
                    temp_result = operand1 - operand2;
                    break;
                case '*':
                    temp_result = operand1 * operand2;
                    break;
                case '/':
                    temp_result = operand1 / operand2;
                    break;
            }
            result = temp_result;
        }
        token = strtok(NULL, " ");
    }
    return result;
}

// Function to print the usage instructions
void print_usage() {
    printf("Usage:./calculator [expression]\n");
}

// Function to handle invalid input
void handle_invalid_input(char *input) {
    printf("Invalid input: %s\n", input);
    print_usage();
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        handle_invalid_input(argv[0]);
        return 1;
    }
    char *expression = argv[1];
    if (strlen(expression) > MAX_INPUT_SIZE) {
        handle_invalid_input(expression);
        return 1;
    }
    double result = evaluate_expression(expression);
    printf("Result: %.2f\n", result);
    return 0;
}