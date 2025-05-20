//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    double result;
    char operator;
} Calculator;

void calculator_init(Calculator *calc) {
    calc->pos = 0;
    calc->result = 0.0;
    calc->operator = '\0';
    calc->buffer[0] = '\0';
}

void calculator_add(Calculator *calc, char num) {
    if (calc->pos >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[calc->pos++] = num;
    calc->buffer[calc->pos] = '\0';
}

void calculator_set_operator(Calculator *calc, char operator) {
    calc->operator = operator;
}

double calculator_calculate(Calculator *calc) {
    double a, b, result;
    a = atof(calc->buffer);
    b = atof(calc->buffer + calc->pos - 1);
    switch (calc->operator) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = b - a;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) {
                return 0.0;
            }
            result = b / a;
            break;
    }
    calc->result = result;
    return result;
}

int main() {
    Calculator calc;
    calculator_init(&calc);

    char input;
    double result;

    printf("Enter an expression: ");
    scanf("%c", &input);

    while (input != '\n') {
        calculator_add(&calc, input);
        scanf("%c", &input);
    }

    calculator_set_operator(&calc, input);

    result = calculator_calculate(&calc);

    if (result != 0.0) {
        printf("Result: %.2lf\n", result);
    } else {
        printf("Error: division by zero\n");
    }

    return 0;
}