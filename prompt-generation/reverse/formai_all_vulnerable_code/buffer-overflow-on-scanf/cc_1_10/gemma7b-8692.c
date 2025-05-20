//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->top = -1;
    calc->result = 0.0;
    return calc;
}

void calculator_push(Calculator* calc, char number) {
    calc->buffer[++calc->top] = number;
}

double calculator_pop(Calculator* calc) {
    if (calc->top == -1) {
        return 0.0;
    } else {
        return (double)calc->buffer[calc->top] - '0';
    }
}

double calculator_calculate(Calculator* calc) {
    double result = 0.0;
    switch (calc->buffer[0]) {
        case '+':
            result = calculator_pop(calc) + calculator_pop(calc);
            break;
        case '-':
            result = calculator_pop(calc) - calculator_pop(calc);
            break;
        case '*':
            result = calculator_pop(calc) * calculator_pop(calc);
            break;
        case '/':
            result = calculator_pop(calc) / calculator_pop(calc);
            break;
        case '^':
            result = pow(calculator_pop(calc), calculator_pop(calc));
            break;
        default:
            result = calculator_pop(calc);
    }
    calc->result = result;
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

    calculator_calculate(calc);

    printf("Result: %.2lf\n", calc->result);

    free(calc);

    return 0;
}