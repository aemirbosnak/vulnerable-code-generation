//MISTRAL-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Calculator {
    char expression[256];
    double stack[16];
    int top;
} Calculator;

void push(Calculator *calculator, double value) {
    if (calculator->top >= 16) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    calculator->stack[calculator->top++] = value;
}

double pop(Calculator *calculator) {
    if (calculator->top <= 0) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return calculator->stack[--calculator->top];
}

void calculate(Calculator *calculator) {
    int i, length = strlen(calculator->expression);
    for (i = 0; i < length; i++) {
        if (calculator->expression[i] >= '0' && calculator->expression[i] <= '9') {
            double number = 0;
            int j = i;
            while (calculator->expression[j] >= '0' && calculator->expression[j] <= '9') {
                number = number * 10 + (calculator->expression[j] - '0');
                j++;
            }
            i = j;
            push(calculator, number);
        } else if (calculator->expression[i] == '+') {
            double a = pop(calculator);
            double b = pop(calculator);
            push(calculator, a + b);
        } else if (calculator->expression[i] == '-') {
            double a = pop(calculator);
            double b = pop(calculator);
            push(calculator, b - a);
        } else if (calculator->expression[i] == '*') {
            double a = pop(calculator);
            double b = pop(calculator);
            push(calculator, a * b);
        } else if (calculator->expression[i] == '/') {
            double a = pop(calculator);
            double b = pop(calculator);
            push(calculator, b / a);
        } else if (calculator->expression[i] == '^') {
            double a = pop(calculator);
            double b = pop(calculator);
            push(calculator, pow(b, a));
        }
    }
    if (calculator->top != 1) {
        printf("Error in expression\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    Calculator calculator;
    printf("Enter the expression: ");
    scanf("%s", calculator.expression);
    calculate(&calculator);
    printf("Result: %.2f\n", calculator.stack[0]);
    return 0;
}