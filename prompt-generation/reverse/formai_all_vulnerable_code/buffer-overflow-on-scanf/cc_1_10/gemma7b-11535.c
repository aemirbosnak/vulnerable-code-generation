//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    double result;
} Calculator;

Calculator* calculator_new() {
    Calculator* calculator = malloc(sizeof(Calculator));
    calculator->position = 0;
    calculator->result = 0.0;
    return calculator;
}

void calculator_add(Calculator* calculator, double number) {
    calculator->buffer[calculator->position++] = number;
    calculator->result += number;
}

void calculator_subtract(Calculator* calculator, double number) {
    calculator->buffer[calculator->position++] = number;
    calculator->result -= number;
}

void calculator_multiply(Calculator* calculator, double number) {
    calculator->buffer[calculator->position++] = number;
    calculator->result *= number;
}

void calculator_divide(Calculator* calculator, double number) {
    calculator->buffer[calculator->position++] = number;
    calculator->result /= number;
}

double calculator_get_result(Calculator* calculator) {
    return calculator->result;
}

int main() {
    Calculator* calculator = calculator_new();

    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    char* token = strtok(input, " ");

    while (token) {
        double number = atof(token);
        switch (*token) {
            case '+':
                calculator_add(calculator, number);
                break;
            case '-':
                calculator_subtract(calculator, number);
                break;
            case '*':
                calculator_multiply(calculator, number);
                break;
            case '/':
                calculator_divide(calculator, number);
                break;
            default:
                break;
        }
        token = strtok(NULL, " ");
    }

    double result = calculator_get_result(calculator);

    printf("The result is: %.2lf\n", result);

    return 0;
}