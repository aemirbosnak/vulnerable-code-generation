//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
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
    if (number == 0) {
        printf("Error: division by zero is not allowed.\n");
        return;
    }
    calculator->buffer[calculator->position++] = number;
    calculator->result /= number;
}

double calculator_get_result(Calculator* calculator) {
    return calculator->result;
}

int main() {
    Calculator* calculator = calculator_init();

    char command;
    double number;

    printf("Enter a command (add, subtract, multiply, divide, result): ");
    scanf("%c", &command);

    switch (command) {
        case 'a':
            printf("Enter a number: ");
            scanf("%lf", &number);
            calculator_add(calculator, number);
            break;
        case 's':
            printf("Enter a number: ");
            scanf("%lf", &number);
            calculator_subtract(calculator, number);
            break;
        case 'm':
            printf("Enter a number: ");
            scanf("%lf", &number);
            calculator_multiply(calculator, number);
            break;
        case 'd':
            printf("Enter a number: ");
            scanf("%lf", &number);
            calculator_divide(calculator, number);
            break;
        case 'r':
            printf("The result is: %.2lf\n", calculator_get_result(calculator));
            break;
        default:
            printf("Invalid command.\n");
    }

    free(calculator);

    return 0;
}