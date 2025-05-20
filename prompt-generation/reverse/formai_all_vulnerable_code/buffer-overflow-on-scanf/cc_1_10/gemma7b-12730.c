//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HISTORY 10

typedef struct Calculator {
    char operator;
    double operand1;
    double operand2;
    double result;
    int historyIndex;
} Calculator;

Calculator calculators[MAX_HISTORY];

void addHistory(Calculator calculator) {
    int i = 0;
    for (; i < MAX_HISTORY && calculators[i].historyIndex != -1; i++) {}
    calculator.historyIndex = i;
    calculators[i] = calculator;
}

double calculate(Calculator calculator) {
    switch (calculator.operator) {
        case '+':
            return calculator.result = calculator.operand1 + calculator.operand2;
        case '-':
            return calculator.result = calculator.operand1 - calculator.operand2;
        case '*':
            return calculator.result = calculator.operand1 * calculator.operand2;
        case '/':
            return calculator.result = calculator.operand1 / calculator.operand2;
        case '^':
            return calculator.result = pow(calculator.operand1, calculator.operand2);
        default:
            return -1;
    }
}

int main() {
    char operator;
    double operand1, operand2, result;
    int historyIndex = 0;
    Calculator calculator;

    while (1) {
        printf("Enter operator (+, -, *, /, ^, =): ");
        scanf(" %c", &operator);

        if (operator == '=') {
            printf("Enter operand 1: ");
            scanf(" %lf", &operand1);
            printf("Enter operand 2: ");
            scanf(" %lf", &operand2);

            calculator.operator = operator;
            calculator.operand1 = operand1;
            calculator.operand2 = operand2;
            calculator.result = calculate(calculator);

            addHistory(calculator);

            printf("Result: %.2lf\n", calculator.result);
            historyIndex++;
        } else if (operator == 'H') {
            int i = 0;
            for (; i < historyIndex && calculators[i].historyIndex != -1; i++) {
                printf("Operator: %c, Operand 1: %.2lf, Operand 2: %.2lf, Result: %.2lf\n", calculators[i].operator, calculators[i].operand1, calculators[i].operand2, calculators[i].result);
            }
        } else if (operator == 'C') {
            historyIndex = 0;
            printf("History cleared.\n");
        } else {
            printf("Invalid operator.\n");
        }
    }

    return 0;
}