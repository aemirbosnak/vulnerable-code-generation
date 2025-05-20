//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    int history[10];
    int historyIndex;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->top = 0;
    calc->historyIndex = 0;
    return calc;
}

void calculator_push(Calculator* calc, char number) {
    if (calc->top == MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[calc->top++] = number;
}

double calculator_pop(Calculator* calc) {
    if (calc->top == 0) {
        return 0;
    }
    return (double)calc->buffer[calc->top--];
}

void calculator_clear(Calculator* calc) {
    calc->top = 0;
}

double calculator_calculate(Calculator* calc) {
    double result = 0;
    char operator = '\0';
    for (int i = 0; i < calc->top; i++) {
        char number = calc->buffer[i];
        if (operator == '+') {
            result += calculator_pop(calc) + number;
        } else if (operator == '-') {
            result -= calculator_pop(calc) - number;
        } else if (operator == '*') {
            result *= calculator_pop(calc) * number;
        } else if (operator == '/') {
            result /= calculator_pop(calc) / number;
        } else {
            operator = number;
        }
    }
    return result;
}

int main() {
    Calculator* calc = calculator_init();
    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        calculator_push(calc, input[i]);
    }

    double result = calculator_calculate(calc);

    printf("The result is: %.2lf\n", result);

    return 0;
}