//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    float result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->top = -1;
    calc->result = 0.0f;
    return calc;
}

void calculator_push(Calculator* calc, char number) {
    if (calc->top == MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[++calc->top] = number;
}

float calculator_pop(Calculator* calc) {
    if (calc->top == -1) {
        return -1.0f;
    }
    return (float)calc->buffer[calc->top] - '0';
}

void calculator_clear(Calculator* calc) {
    calc->top = -1;
    calc->result = 0.0f;
}

void calculator_execute(Calculator* calc) {
    char operator = calc->buffer[0];
    float num1 = calculator_pop(calc);
    float num2 = calculator_pop(calc);

    switch (operator) {
        case '+':
            calc->result = num1 + num2;
            break;
        case '-':
            calc->result = num1 - num2;
            break;
        case '*':
            calc->result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                return;
            }
            calc->result = num1 / num2;
            break;
        default:
            return;
    }
}

int main() {
    Calculator* calc = calculator_init();

    char input[MAX_BUFFER_SIZE];
    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        calculator_push(calc, input[i]);
    }

    calculator_execute(calc);

    printf("The result is: %.2f\n", calc->result);

    calculator_clear(calc);

    return 0;
}